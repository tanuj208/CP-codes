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


typedef int ll;
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

vector<pii> e;
vector<pii> ad[100005];
map<pii,ll> cnt;
vector<ll> deg(100005,0);
vector<ll> cntDeg(100005,0);
vector<bool> bridge(100005);
vector<ll> vis(100005,0);
vector<ll> disc(100005);
vector<ll> low(100005);
vector<ll> parent(100005,-1);
ll n,m;
ll timee = 0;

void bridgeUtil(int u)
{ 
	vis[u]=1; 
	disc[u] = low[u] = ++timee; 
	ll i;
	for(i=0;i<sz(ad[u]);i++)
	{ 
		ll v = ad[u][i].ff;
		ll eno=ad[u][i].ss;
		if (vis[v]==0)
		{ 
			parent[v] = u;
			bridgeUtil(v);
			low[u]  = min(low[u], low[v]);
			if (low[v] > disc[u])
				bridge[eno]=true;
		}
		else if (v != parent[u]) 
			low[u]  = min(low[u], disc[v]); 
	} 
} 

void bridgeCalc()
{
	ll i;
	for(i=0;i<=m;i++)
		bridge[i]=false;
	for (i=1;i<=n;i++) 
		if (vis[i]!=1) 
			bridgeUtil(i);
}

map<pii,ll> anMap; // no of edges bw edge and degree vertex

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i,j;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(mp(v,i));
		ad[v].pb(mp(u,i));
		e.pb(mp(u,v));
		deg[u]++;
		deg[v]++;
	}
	bridgeCalc();
	for(i=1;i<=n;i++)
	{
		cntDeg[deg[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<sz(ad[i]);j++)
		{
			ll x=ad[i][j].ff;
			if(anMap.find(mp(i,deg[x]))!=anMap.end())
				anMap[mp(i,deg[x])]++;
			else
				anMap[mp(i,deg[x])]=1;
		}
	}
	for(i=0;i<m;i++)
	{
		ll u=deg[e[i].ff];
		ll v=deg[e[i].ss];
		if(cnt.find(mp(u,v))==cnt.end())
		{
			cnt[mp(u,v)]=1;
			cnt[mp(v,u)]=1;
		}
		else
		{
			cnt[mp(u,v)]++;
			cnt[mp(v,u)]++;
		}
	}
	long long ans=0;
	for(i=0;i<m;i++)
	{
		ll u=e[i].ff;
		ll v=e[i].ss;
		if(bridge[i])
			continue;
		ll deg1=deg[u];
		ll deg2=deg[v];
		cntDeg[deg1]--;
		cntDeg[deg2]--;
		if(deg1!=deg2)
		{
			ans+=((long long)cntDeg[deg1-1])*(long long)(cntDeg[deg2-1])-cnt[mp(deg1-1,deg2-1)];
			if(deg2==deg1-1)
				ans+=anMap[mp(v,deg2-1)];
			if(deg1==deg2-1)
				ans+=anMap[mp(u,deg1-1)];
			ans+=cntDeg[deg2-1]-anMap[mp(u,deg2-1)];
			ans+=cntDeg[deg1-1]-anMap[mp(v,deg1-1)];
		}
		else
		{
			ll xx=cntDeg[deg1-1];
			ans+=((long long)xx*(long long)(xx-1))/2;
			ans-=cnt[mp(deg1-1,deg1-1)];
			ans+=cntDeg[deg1-1]-anMap[mp(u,deg1-1)];
			ans+=cntDeg[deg1-1]-anMap[mp(v,deg1-1)];
		}
		cntDeg[deg1]++;
		cntDeg[deg2]++;
	}
	cout<<ans<<endl;
	return 0;
}