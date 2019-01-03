#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define ff first
#define ss second

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<pii> cor;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		cor.pb(mp(x,y));
	}
	vector<pii> clue;
	set<pii> ans;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		clue.pb(mp(x,y));
	}
	ll j;
	for(i=0;i<n;i++)
	{
		ans.insert(mp(cor[i].ff+clue[0].ff,cor[i].ss+clue[0].ss));
	}
	for(i=1;i<n;i++)
	{
		set<pii> tmp;
		for(j=0;j<n;j++)
		{
			ll x=clue[i].ff+cor[j].ff;
			ll y=clue[i].ss+cor[j].ss;
			if(ans.find(mp(x,y))!=ans.end())
				tmp.insert(mp(x,y));
		}
		ans=tmp;
	}
	auto it=ans.begin();
	cout<<it->first<<" "<<it->second<<endl;
	return 0;
}