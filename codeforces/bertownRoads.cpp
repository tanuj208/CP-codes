#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[100005];
vector<ll> u(300005),v(300005);
vector<ll> arr(100005,-1);
vector<ll> vis(300005,0);
vector<ll> visited(100005,0);
ll t=0;

ll getEdge(ll e, ll i)
{
	if(u[i]==e)
		return v[i];
	else
		return u[i];
}

ll dfs(ll x,ll e=-1)
{
	ll i;
	arr[x]=t;
	t++;
	ll p=arr[x];
	for(i=0;i<ad[x].size();i++)
	{
		ll edge=ad[x][i];
		ll u=getEdge(x,edge);
		// cout<<x<<" "<<u<<endl;
		if(edge!=e)
		{
			if(arr[u]!=-1)
			{
				p=min(p,arr[u]);
			}
			else
			{
				p=min(p,dfs(u,edge));
			}
		}
	}	
	if(p==arr[x] && x!=1)
	{
		cout<<"0\n";
		exit(0);
	}
	return p;
}

void dfs2(ll v)
{
	ll i;
	visited[v]=1;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=getEdge(v,ad[v][i]);
		if(vis[ad[v][i]]==1)
			continue;
		cout<<v<<" "<<x<<"\n";
		vis[ad[v][i]]=1;
		if(visited[x]==1)
			continue;
		dfs2(x);
	}
	return;
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
		ll a,b;
		cin>>a>>b;
		ad[a].pb(i);
		ad[b].pb(i);
		u[i]=a;
		v[i]=b;
	}
	dfs(1);
	dfs2(1);
	return 0;
}