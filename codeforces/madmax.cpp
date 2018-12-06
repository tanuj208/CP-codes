#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pii> ad[104];
ll dp[105][105][27];
// 1 means max won

void calc(ll u,ll v,ll c)
{
	if(dp[u][v][c]!=-1)
		return;
	ll i,j;
	for(i=0;i<sz(ad[u]);i++)
	{
		ll flag=0;
		pii x1=ad[u][i];
		if(x1.second<c)
			continue;
		for(j=0;j<sz(ad[v]);j++)
		{
			pii x2=ad[v][j];
			if(x2.second<x1.second)
				continue;
			calc(x1.first,x2.first,x2.second);
			if(dp[x1.first][x2.first][x2.second]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			dp[u][v][c]=1;
			break;
		}
	}
	if(dp[u][v][c]==-1)
		dp[u][v][c]=0;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i,j,k;
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		char x;
		cin>>x;
		ad[a].pb(mp(b,(ll)x-(ll)'a'));
	}
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
			for(k=0;k<=26;k++)
				dp[i][j][k]=-1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			calc(i,j,0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dp[i][j][0]==0)
				cout<<"B";
			else
				cout<<"A";
		}
		cout<<endl;
	}
	return 0;
}