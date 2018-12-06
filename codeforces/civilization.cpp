#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[300005];
vector<ll> p(300005,-1);
vector<ll> c(300005,0);

ll parent(ll v)
{
	if(p[v]==-1)
		return v;
	p[v]=parent(p[v]);
	return p[v];
}

vector<ll> ht(300005,0);
vector<ll> diameter(300005,0);
vector<ll> visited(300005,0);
ll d=0;

void dfs(ll v,ll p)
{
	if(visited[v]==1)
		return;
	visited[v]=1;
	ll i;
	vector<ll> temp;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		dfs(x,v);
		temp.pb(ht[x]);
	}
	if(sz(temp)==0)
	{
		ht[v]=0;
		d=max(d,(ll)0);
		return;
	}
	sort(temp.begin(),temp.end());
	ll len=sz(temp);
	ht[v]=temp[len-1]+1;
	if(sz(temp)==1)
	{
		d=max(d,ht[v]);
		return;
	}
	d=max(d,2+temp[len-1]+temp[len-2]);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,q;
	cin>>n>>m>>q;
	ll i;
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
		ll x=parent(a);
		ll y=parent(b);
		if(c[x]<c[y])
		{
			p[x]=y;
			c[y]+=c[x];
		}
		else
		{
			p[y]=x;
			c[x]+=c[y];
		}
	}
	for(i=1;i<=n;i++)
	{
		ll x=parent(i);
		d=0;
		dfs(x,0);
		diameter[x]=max(diameter[x],d);
	}
	while(q--)
	{
		ll a;
		cin>>a;
		if(a==1)
		{
			ll b;
			cin>>b;
			ll x=parent(b);
			cout<<diameter[x]<<"\n";
		}
		else
		{
			ll b,e;
			cin>>b>>e;
			ll x=parent(b);
			ll y=parent(e);
			if(x==y)
				continue;
			else
			{
				if(c[x]<c[y])
				{
					p[x]=y;
					c[y]+=c[x];
					diameter[y]=max(max(diameter[x],diameter[y]),(diameter[x]+1)/2+(diameter[y]+1)/2+1);
				}
				else
				{
					p[y]=x;
					c[x]+=c[y];
					diameter[x]=max(max(diameter[x],diameter[y]),(diameter[x]+1)/2+(diameter[y]+1)/2+1);
				}
			}
		}
	}
	return 0;
}