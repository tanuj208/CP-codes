#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

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
	vector<pii> land;
	ll i;
	for(i=0;i<n;i++)
	{
		ll l,w;
		cin>>l>>w;
		if(l<w)
			swap(l,w);
		land.pb(mp(l,w));
	}
	sort(all(land));
	reverse(all(land));
	ll cur_max_w = land[0].ss;
	double ans = (double)(land[0].ff*land[0].ss) / (double)2;
	for(i=1;i<n;i++)
	{
		double cur_area = land[i].ff*land[i].ss;
		ans = max(ans, cur_area/2);
		ll curl = land[i].ff;
		ll opt_wid = min(cur_max_w, land[i].ss);
		ans = max(ans, (double)(curl*opt_wid));
		cur_max_w = max(cur_max_w, land[i].ss);
	}
	cout<<ans;
	if(round(ans) == ans)
		cout<<".0";
	cout<<endl;
	return 0;
}