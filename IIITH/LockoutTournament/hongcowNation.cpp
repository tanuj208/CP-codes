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

vector<ll> vis(100005, 0);
vector<ll> ed_vis(100005, 0);
vector<pii> ad[100005];

void dfs(ll v, ll& vtx_cnt, ll& edge_cnt)
{
	if(vis[v] == 1)
		return;
	vtx_cnt++;
	vis[v] = 1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x = ad[v][i].ff;
		ll idx = ad[v][i].ss;
		if(ed_vis[idx] == 1)
			continue;
		edge_cnt++;
		ed_vis[idx] = 1;
		dfs(x, vtx_cnt, edge_cnt);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll> c;
	ll i;
	for(i=0;i<k;i++)
	{
		ll val;
		cin>>val;
		c.pb(val);
	}
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(mp(v, i));
		ad[v].pb(mp(u, i));
	}
	ll max_vtx_cnt = 0;
	ll ans = 0;
	for(i=0;i<k;i++)
	{
		ll xx = c[i];
		ll vtx_cnt = 0;
		ll edge_cnt = 0;
		dfs(xx, vtx_cnt, edge_cnt);
		max_vtx_cnt = max(max_vtx_cnt, vtx_cnt);
		ll max_edge = (vtx_cnt*(vtx_cnt-1))/2;
		ans += max_edge - edge_cnt;
	}
	ll cnt = 0;
	for(i=1;i<=n;i++)
		if(vis[i] == 0)
			cnt++;
	for(i=0;i<cnt;i++)
		ans += max_vtx_cnt + i;
	for(i=0;i<m;i++)
		if(ed_vis[i] == 0)
			ans--;
	cout<<ans<<endl;
	return 0;
}
