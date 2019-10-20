#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n;
vector<ll> c(200005,0);
vector<pii> ad[200005];
vector<ll> d(200005,0);
vector<ll> p(200005);
vector<ll> l(200005,0);
vector<ll> ans(200005,0);
ll dp[200005][30];

void dfs(ll v)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].first;
		ll w=ad[v][i].second;
		l[x]=l[v]+1;
		d[x]=d[v]+w;
		dfs(x);
	}
	return;
}

void preprocessing()
{
	ll i,j;
	for(i=0;i<=200000;i++)
		for(j=0;j<=25;j++)
			dp[i][j]=0;
	for(i=1;i<=n;i++)
		dp[i][0]=p[i];
	dp[1][0]=0;
	for(j=1;j<=25;j++)
		for(i=1;i<=n;i++)
			if(dp[i][j-1]!=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
	return;
}

void dfs2(ll v)
{
	ll i,j;
	ll dd=d[v]-c[v];
	ll tmp=v;
	for(j=25;j>=0;j--)
		if(dp[tmp][j]!=0)
			if(d[dp[tmp][j]]>=dd)
				tmp=dp[tmp][j];
	if(tmp!=0)
		ans[p[tmp]]--,ans[p[v]]++;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].first;
		dfs2(x);
	}
	return;
}

ll xx=0;

void dfs3(ll v)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].first;
		dfs3(x);
		ans[v]+=ans[x];
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	for(i=1;i<=n;i++)
		cin>>c[i];
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		p[i+1]=a;
		ad[a].pb(mp(i+1,b));
	}
	dfs(1);
	preprocessing();
	dfs2(1);
	dfs3(1);
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}