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

vector<ll> ad[3003];
vector<ll> deg(3003, 0);
vector<pii> edges;
map<pii,ll> edge_to_idx;
vector<ll> vis(3005,0);

vector<ll> dist(3005, 0);

void dfs(ll v, ll p)
{
	ll i;
	ll cur_dist=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		dfs(x,v);
		cur_dist=max(cur_dist, 1+dist[x]);
	}
	dist[v]=cur_dist;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	cin>>n;
	for(i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
		deg[u]++;
		deg[v]++;

		edges.pb(mp(u,v));
		edge_to_idx[mp(u,v)]=i-1;
		edge_to_idx[mp(v,u)]=i-1;
	}
	ll ans=1;
	ll mx=LLONG_MIN;
	ll cur_dist=LLONG_MIN;
	ll idx=-1;
	for(i=0;i<sz(edges);i++)
	{
		ll u=edges[i].ff;
		ll v=edges[i].ss;
		if(mx<deg[u]+deg[v])
		{
			mx=deg[u]+deg[v];
			idx=i;
			dfs(u,v);
			dfs(v,u);
			cur_dist=dist[u]+dist[v];
		}
		else if(mx==deg[u]+deg[v])
		{
			dfs(u,v);
			dfs(v,u);
			if(cur_dist < dist[u]+dist[v])
			{
				idx=i;
				cur_dist=dist[u]+dist[v];
			}
		}
	}
	ans+=mx-2;
	ll u=edges[idx].ff;
	ll v=edges[idx].ss;
	dfs(u,v);
	dfs(v,u);
	ll elen;
	vis[idx]=1;
	for(elen=2;elen<n;elen++)
	{
		mx=LLONG_MIN;
		ll dist_val=LLONG_MIN;
		ll uu=-1; // 0 if update u else update v
		ll vtx=-1; // new vtx
		idx=-1;
		for(i=0;i<sz(ad[u]);i++)
		{
			ll x=ad[u][i];
			ll eidx=edge_to_idx[mp(x,u)];
			if(vis[eidx]==1)
				continue;
			ll add_ans=1+elen*(deg[v]+deg[x]-2);
			if(mx<add_ans || (mx==add_ans && dist_val < dist[x]))
			{
				mx=add_ans;
				uu=0;
				vtx=x;
				idx=eidx;
				dist_val=dist[x];
			}
		}

		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			ll eidx=edge_to_idx[mp(v,x)];
			if(vis[eidx]==1)
				continue;
			ll add_ans=1+elen*(deg[u]+deg[x]-2);
			if(mx<add_ans || (mx==add_ans && dist_val < dist[x]))
			{
				mx=add_ans;
				uu=1;
				vtx=x;
				idx=eidx;
				dist_val=dist[x];
			}
		}
		if(mx==LLONG_MIN)
			break;
		vis[idx]=1;
		ans+=mx;
		if(uu==0)
			u=vtx;
		else
			v=vtx;
	}
	cout<<ans<<endl;
	return 0;
}