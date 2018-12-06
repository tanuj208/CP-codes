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

vector<ll> ad[300005];
ll vis[300005];
vector<ll> arr(300005);
vector<bool> isBridge(300005, false);
ll T=0;
vector<pii> ed;

ll othVer(ll x, ll i)
{
	if(ed[i].first==x)
		return ed[i].second;
	else
		return ed[i].first;
}

ll dfs0(ll v, ll edge)
{
	ll i;
	vis[v]=1;
	arr[v]=T++;
	ll val=arr[v];
	for(i=0;i<sz(ad[v]);i++)
	{
		ll edInd=ad[v][i];
		ll oth=othVer(v, edInd);
		if(vis[oth]==0)
			val=min(val, dfs0(oth, edInd));
		else if(edInd!=edge)
			val=min(val, arr[oth]);
	}
	if(val==arr[v] && edge != -1)
		isBridge[edge]=true;
	return val;
}

ll cmpno=0;
queue<ll> q[300005];
vector<ll> tre[300005];
ll ans=0;

void dfs1(ll v)
{
	ll curCmp=cmpno;
	q[curCmp].push(v);
	vis[v]=1;
	ll i;
	while(!q[curCmp].empty())
	{
		ll vv=q[curCmp].front();
		q[curCmp].pop();
		for(i=0;i<sz(ad[vv]);i++)
		{
			ll ed=ad[vv][i];
			ll oth=othVer(vv, ed);
			if(vis[oth]==1)
				continue;
			if(isBridge[ed])
			{
				cmpno++;
				tre[cmpno].pb(curCmp);
				tre[curCmp].pb(cmpno);
				dfs1(oth);
			}
			else
			{
				q[curCmp].push(oth);
				vis[oth]=1;
			}
		}
	}
}

ll dfs2(ll v, ll p)
{
	ll i;
	ll mx=-1;
	ll secondmx=-1;
	for(i=0;i<sz(tre[v]);i++)
	{
		ll x=tre[v][i];
		if(x==p)
			continue;
		ll tmp=dfs2(x, v);
		if(mx<tmp)
			secondmx=mx, mx=tmp;
		else if(secondmx<tmp)
			secondmx=tmp;
	}
	ans=max(ans, 2+mx+secondmx);
	return mx+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(i);
		ad[v].pb(i);
		ed.pb(mp(u,v));
	}
	memset(vis, 0, sizeof(vis));
	dfs0(1,-1);
	memset(vis, 0, sizeof(vis));
	dfs1(1);
	dfs2(0,-1);
	// for(i=0;i<=cmpno;i++)
	// {
	// 	for(ll j=0;j<sz(tre[i]);j++)
	// 		cout<<i<<" "<<tre[i][j]<<endl;
	// }
	cout<<ans<<endl;
	return 0;
}