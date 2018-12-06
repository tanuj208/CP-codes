#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> ad[100006];
vector<ll> l(100006,0);
vector<ll> p(100006,0);
ll dp[100005][30];
ll n,q;

void preCalc()
{
	ll i,j;
	for(i=0;i<=100000;i++)
		for(j=0;j<=25;j++)
			dp[i][j]=-1;
	for(i=2;i<=n;i++)
		dp[i][0]=p[i];
	for(j=1;j<=25;j++)
		for(i=1;i<=n;i++)
			if(dp[i][j-1]!=-1)
				dp[i][j]=dp[dp[i][j-1]][j-1];
	return;
}

void dfs(ll v,ll pa)
{
	p[v]=pa;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==pa)
			continue;
		l[x]=l[v]+1;
		dfs(x,v);
	}
	return;
}

ll lcaCalc(ll a,ll b)
{
	ll i;
	if(l[a]<l[b])
	{
		ll temp=b;
		b=a;
		a=temp;
	}
	ll j;
	for(j=25;j>=0;j--)
		if(dp[a][j]!=-1 && l[dp[a][j]]>=l[b])
			a=dp[a][j];
	if(a==b)
		return a;
	for(i=25;i>=0;i--)
	{
		if(dp[a][i]!=-1 && dp[b][i]!=dp[a][i])
		{
			a=dp[a][i];
			b=dp[b][i];
		}
	}
	return p[a];
}

ll maximum(ll x1,ll x2,ll x3,ll x4,ll x5,ll x6)
{
	return max(x1,max(x2,max(x3,max(x4,max(x5,x6)))));
}

ll ansCalc(ll a,ll b,ll c)
{
	// a se c and b se c
	ll x=lcaCalc(a,c);
	if(x==a)
	{
		ll x1=lcaCalc(b,c);
		if(l[x1]>=l[c])
			return 0;
		else
			return min(l[c]-l[x1],l[c]-l[a]);
	}
	else if(x==c)
	{
		ll x1=lcaCalc(a,b);
		if(l[x1]>=l[a])
			return l[a]-l[c];
		else if(l[x1]<l[c])
			return 0;
		else
			return l[x1]-l[c];
	}
	else
	{
		ll x1=lcaCalc(a,b);
		ll ans=0;
		if(l[x1]>=l[a])
			ans=l[a]-l[x];
		else if(l[x1]<l[x])
			ans=0;
		else
			ans=l[x1]-l[x];
		x1=lcaCalc(b,c);
		if(l[x1]>=l[c])
			return 0;
		else if(l[x1]<=l[x])
			return ans+l[c]-l[x];
		else
			return l[c]-l[x1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	ll i;
	for(i=2;i<=n;i++)
	{
		ll val;
		cin>>val;
		ad[i].pb(val);
		ad[val].pb(i);
	}
	dfs(1,0);
	preCalc();
	while(q--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll x1=ansCalc(a,b,c);
		ll x2=ansCalc(a,c,b);
		ll x3=ansCalc(b,a,c);
		ll x4=ansCalc(b,c,a);
		ll x5=ansCalc(c,a,b);
		ll x6=ansCalc(c,b,a);
		if(a==b)
		{
			cout<<x1+1<<"\n";
			continue;
		}
		if(b==c)
		{
			cout<<x4+1<<"\n";
			continue;
		}
		if(a==c)
		{
			cout<<x2+1<<"\n";
			continue;
		}
		cout<<maximum(x1,x2,x3,x4,x5,x6)+1<<"\n";
	}
	return 0;
}