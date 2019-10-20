#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long ll;
typedef pair<int,int> pii;

const int lt=100005;
int mod=1000000007;
vector<int> ad[1000005];
int dp[1000005][25];
vector<int> l(1000005,0);
vector<int> p(1000005,0);
vector<int> lenge(1000005,0);
int rem;
int n,k;

void dfs(int v,int par)
{
	int i;
	for(i=0;i<sz(ad[v]);i++)
	{
		int x=ad[v][i];
		if(x==par)
			continue;
		l[x]=l[v]+1;
		p[x]=v;
		dfs(x,v);
	}
	return;
}

void precalc()
{
	int i,j;
	for(i=0;i<=1000000;i++)
		for(j=0;j<=22;j++)
			dp[i][j]=0;
	for(i=1;i<=n;i++)
		dp[i][0]=p[i];
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			if(dp[i][j-1]!=0)
				dp[i][j]=dp[dp[i][j-1]][j-1];
	return;
}

void dist(int v)
{
	int i;
	int dist=0;
	int tmpv=v;
	for(i=20;i>=0;i--)
		if(dp[v][i]!=0 && lenge[dp[v][i]]==0)
			v=dp[v][i],dist+=(1<<i);
	v=tmpv;
	if(dist<rem)
		while(lenge[v]!=1)
			lenge[v]=1,v=p[v],rem--;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	rem=n-k-1;
	int i,val;
	for(i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	dfs(n,0);
	precalc();
	lenge[n]=1;
	for(i=n-1;i>=0;i--)
		dist(i);
	for(i=1;i<=n;i++)
		if(lenge[i]==0)
			cout<<i<<" ";
	cout<<endl;
	return 0;
}