#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pii> ad[100005];
vector<ll> arr(100005);
vector<ll> chainHead(100005),chainInd(100005),chainSize(100005),chainPos(100005);
vector<ll> vis(100005,0);
vector<ll> p(100005,0),st(100005,0),l(100005,0);
ll dp[100005][30];
ll n;
ll chainNo=0;

void reset()
{
	ll i,j;
	chainNo=0;
	for(i=0;i<=100000;i++)
	{
		ad[i].clear();
		chainHead[i]=-1;
		chainSize[i]=0;
		vis[i]=0;
		st[i]=0;
		p[i]=0;
		l[i]=0;
		for(j=0;j<=25;j++)
			dp[i][j]=0;
	}
	return;
}

void dfs(ll v)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].first;
		p[x]=v;
		l[x]=l[v]+1;
		dfs(x);
		st[v]+=st[x];
	}
	st[v]++;
	return;
}

void hld(ll v)
{
	ll i;
	if(chainHead[chainNo]==-1)
		chainHead[chainNo]=v;
	chainInd[v]=chainNo;
	chainPos[v]=chainSize[chainNo];
	chainSize[chainNo]++;
	ll ind=-1,subtreeSize=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].first;
		if(st[x]>subtreeSize)
		{
			subtreeSize=st[x];
			ind=i;
		}
	}
	if(ind>=0)
	{
		arr.pb(ad[v][ind].second);
		hld(ad[v][ind].first);
	}
	for(i=0;i<sz(ad[v]);i++)
	{
		if(i==ind)
			continue;
		chainNo++;
		arr.pb(ad[v][ind].second);
		hld(ad[v][i].first);
	}
	return;
}

void preCalc()
{
	ll i,j;
	for(i=1;i<=n;i++)
		dp[i][0]=p[i];
	for(j=1;j<=25;j++)
		for(i=1;i<=n;i++)
			if(dp[i][j-1]!=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
	return;
}

ll lca(ll u,ll v)
{
	ll i,j;
	if(l[u]<l[v])
	{
		ll tmp=u;
		u=v;
		v=tmp;
	}
	// now level of v is less -> v is above u
	for(i=25;i>=0;i--)
		if(dp[u][i]!=0 && l[dp[u][i]]>l[v])
			u=dp[u][i];
	if(u==v)
		return u;
	for(i=25;i>=0;i--)
		if(dp[u][i]!=dp[v][i] && dp[u][i]!=0)
			u=dp[u][i],v=dp[v][i];
	return p[u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		reset();
		cin>>n;
		ll i;
		for(i=1;i<n;i++)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			ad[a].pb(mp(b,c));
			ad[b].pb(mp(a,c));
		}
		preCalc();
		cout<<lca(3,5)<<endl;
	}
	return 0;
}