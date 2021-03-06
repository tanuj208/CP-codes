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

vector<pii> rb,se;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i,j;
	for(i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		rb.pb(mp(a,b));
	}
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		se.pb(mp(a,b));
	}
	vector<ll> min_y_needed(1000005, 0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			pii robber = rb[i];
			pii searchlight = se[j];
			if(robber.ff > searchlight.ff || robber.ss > searchlight.ss)
				continue;
			ll x_diff = searchlight.ff - robber.ff;
			ll y_diff = searchlight.ss - robber.ss;
			min_y_needed[x_diff] = max(min_y_needed[x_diff], y_diff+1);
		}
	}
	ll ans = LLONG_MAX;
	ll y_needed = 0;
	for(i=1000000;i>=0;i--)
	{
		y_needed = max(y_needed, min_y_needed[i]);
		ans = min(ans, i + y_needed);
	}
	cout<<ans<<endl;
	return 0;
}
