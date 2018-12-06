#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,m;
ll dp[100005][30];
vector<ll> ad[100005];
vector<ll> p(100005,0);
vector<ll> l(100005,0);
vector<ll> closestRed(100005,-1);
queue<ll> q;

void dfs(ll v,ll par)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==par)
			continue;
		p[x]=v;
		l[x]=l[v]+1;
		dfs(x,v);
	}
	return;
}

void preProcessing()
{
	ll i,j;
	for(i=0;i<=100000;i++)
		for(j=0;j<=25;j++)
			dp[i][j]=0;
	for(i=1;i<=n;i++)
		dp[i][0]=p[i];
	for(j=1;j<=25;j++)
		for(i=1;i<=n;i++)
			if(dp[i][j-1]!=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
	return;
}

ll shortDist(ll u,ll v)
{
	ll j;	
	ll a=0;
	if(l[u]<l[v])
	{
		ll temp=u;
		u=v;
		v=temp;
	}
	for(j=25;j>=0;j--)
		if(dp[u][j]!=0)
			if(l[dp[u][j]]>=l[v])
				u=dp[u][j],a+=(1<<j);
	if(u==v)
		return a;
	for(j=25;j>=0;j--)
	{
		ll p1=dp[u][j];
		ll p2=dp[v][j];
		if(p1!=0 && p1!=p2)
			u=p1,v=p2,a+=2*(1<<j);
	}
	return a+2;
}

void bfs()
{
	while(!q.empty())
	{
		ll v=q.front();
		q.pop();
		ll i;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			if(closestRed[x]!=-1)
				continue;
			closestRed[x]=1+closestRed[v];
			q.push(x);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	l[1]=0;
	dfs(1,0);
	preProcessing();
	ll mark=sqrt(m);
	ll xxx=mark;
	vector<ll> reds;
	reds.pb(1);
	q.push(1);
	closestRed[1]=0;
	bfs();
	vector<ll> neww;
	for(i=0;i<m;i++)
	{
		if(i==mark)
		{
			mark+=xxx;
			for(ll j=0;j<=100000;j++)
				closestRed[j]=-1;
			for(ll j=0;j<sz(reds);j++)
				q.push(reds[j]),closestRed[reds[j]]=0;
			bfs();
			neww.clear();
		}
		ll t,v;
		cin>>t>>v;
		if(t==1)
		{
			reds.pb(v);
			neww.pb(v);
		}
		else
		{
			ll ans=closestRed[v];
			for(ll j=0;j<sz(neww);j++)
				ans=min(ans,shortDist(neww[j],v));
			cout<<ans<<"\n";
		}
	}
	return 0;
}