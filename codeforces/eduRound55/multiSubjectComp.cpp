#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

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
	ll n,m;
	cin>>n>>m;
	vector<ll> ad[100005];
	vector<ll> maxAns(100005,0);
	ll i;
	for(i=0;i<n;i++)
	{
		ll s,r;
		cin>>s>>r;
		ad[s].pb(r);
	}
	for(i=1;i<=100000;i++)
	{
		sort(ad[i].begin(),ad[i].end());
		reverse(ad[i].begin(),ad[i].end());
	}
	ll j;
	for(i=1;i<=100000;i++)
	{
		ll val=0;
		for(j=0;j<sz(ad[i]);j++)
		{
			val+=ad[i][j];
			if(val<=0)
				break;
			maxAns[j+1]+=val;
		}
	}
	ll ans=LLONG_MIN;
	for(i=1;i<=100000;i++)
		ans=max(ans,maxAns[i]);
	if(ans<0)
		cout<<"0\n";
	else
		cout<<ans<<endl;
	return 0;
}