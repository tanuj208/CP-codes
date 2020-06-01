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

vector<ll> ad[100005];
ll root;

ll dfs(ll v, ll par)
{
	ll ans=0;
	if(v == root && sz(ad[v]) == 1)
		ans++;
	if(sz(ad[v]) == 1 && v!=root)
		return 1;
	ll i;
	ll mx_val = 0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==par)
			continue;
		ll val1 = dfs(x, v);
		mx_val = max(mx_val, val1);
	}
	ans += (mx_val + sz(ad[v]) - 2);
	if(v==root)
		ans++;
	// if(v==3)
	// 	cout<<mx_val<<" "<<ans<<endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<ll> d(n+1, 0);
	for(i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
		d[u]++;
		d[v]++;
	}
	ll mx_deg = 0;
	ll vtx;
	for(i=1;i<=n;i++)
	{
		if(mx_deg < d[i])
		{
			mx_deg = d[i];
			vtx=i;
		}
	}
	root = vtx;
	cout<<dfs(vtx, 0)<<endl;
	// ll ans=0;
	// for(i=1;i<=min((ll)100, n);i++)
	// 	ans=max(ans, dfs(1, 0));
	// cout<<ans<<endl;
	return 0;
}