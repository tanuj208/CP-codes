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
vector<ll> city[100005];
vector<ll> p(100005,0);
vector<ll> l(100005,0);
ll dp[100005][30];
vector<ll> dp2[100005][30];
vector<ll> ans;
ll n,m,q;

void dfs(ll v,ll par)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x!=par)
		{
			p[x]=v;
			l[x]=l[v]+1;
			dfs(x,v);
		}
	}
	return;
}

void preprocessing()
{
	ll i,j,k;
	vector<ll> tmp;
	for(i=0;i<=n;i++)
		for(j=0;j<=25;j++)
			dp[i][j]=0;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=p[i];
		for(k=0;k<min(sz(city[i]),(ll)10);k++)
			dp2[i][0].pb(city[i][k]);
	}
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(dp[i][j-1]!=0)
			{
				ll x=dp[i][j-1];
				dp[i][j]=dp[x][j-1];
				for(k=0;k<sz(dp2[i][j-1]);k++)
					tmp.pb(dp2[i][j-1][k]);
				for(k=0;k<sz(dp2[x][j-1]);k++)
					tmp.pb(dp2[x][j-1][k]);
				sort(tmp.begin(),tmp.end());
				for(k=0;k<min(sz(tmp),(ll)10);k++)
					dp2[i][j].pb(tmp[k]);
				tmp.clear();
			}
		}
	}
	return;
}

void query(ll v,ll u)
{
	ll i,j,k;
	ans.clear();
	if(l[v]<l[u])
	{
		ll tmp=v;
		v=u;
		u=tmp;
	}
	ll logg;
	for(logg=1;1<<logg<=l[v];logg++);
		logg--;
	for(j=logg;j>=0;j--)
	{
		if(dp[v][j]!=0 && l[dp[v][j]]>=l[u])
		{
			for(k=0;k<sz(dp2[v][j]);k++)
				ans.pb(dp2[v][j][k]);
			v=dp[v][j];
		}
	}
	for(j=logg;j>=0;j--)
	{
		if(dp[v][j]!=0 && dp[u][j]!=dp[v][j])
		{
			for(k=0;k<sz(dp2[v][j]);k++)
				ans.pb(dp2[v][j][k]);
			for(k=0;k<sz(dp2[u][j]);k++)
				ans.pb(dp2[u][j][k]);
			v=dp[v][j];
			u=dp[u][j];
		}
	}
	ll xx=1;
	if(u==v)
		xx=0;
	else
		for(k=0;k<sz(dp2[u][0]);k++)
			ans.pb(dp2[u][0][k]);
	for(k=0;k<sz(dp2[v][xx]);k++)
		ans.pb(dp2[v][xx][k]);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>q;
	ll i;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		city[val].pb(i+1);
	}
	for(i=1;i<=n;i++)
		sort(city[i].begin(),city[i].end());
	dfs(1,0);
	preprocessing();
	while(q--)
	{
		ll u,v,a;
		cin>>u>>v>>a;
		query(u,v);
		sort(ans.begin(),ans.end());
		i=0;
		ll x=min(a,sz(ans));
		cout<<x<<" ";
		for(i=0;i<x;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}