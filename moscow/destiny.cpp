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

vector<ll> r;
vector<pii> ad[305];
vector<vector<ll>> dist(305, vector<ll> (12, -1));

ll dfs(ll v, ll tofind)
{
	if(dist[v][tofind] != -1)
		return dist[v][tofind];
	dist[v][tofind] = LLONG_MAX;
	if(tofind == r[v])
	{
		dist[v][tofind] = dfs(v, tofind+1);
		return dist[v][tofind];
	}
	ll min_dist = LLONG_MAX;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x = ad[v][i].ff;
		ll w = ad[v][i].ss;
		ll d = dfs(x, tofind);
		if(d != LLONG_MAX)
			min_dist = min(min_dist, w + d);
	}
	dist[v][tofind] = min_dist;
	return dist[v][tofind];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,e;
	cin>>n>>m>>e;
	ll i;
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		r.pb(val);
	}
	for(i=0;i<e;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		ad[u].pb(mp(v,w));
	}
	ll ans = LLONG_MAX;
	for(i=0;i<m;i++)
		if(r[i] == n-1)
			dist[i][n-1]=0;
	for(i=0;i<m;i++)
		ans = min(ans, dfs(i, 0));
	if(ans == LLONG_MAX)
		ans = -1;
	cout<<ans<<endl;
	return 0;
}