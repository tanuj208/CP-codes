#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll dp[1000][1000];

void func(ll i,ll j)
{
	if(dp[i][j]!=-1)
		return;

	if(dp[i-1][j]==-1)
		func(i-1,j);

	if(dp[i][j-1]==-1)
		func(i,j-1);

	if(dp[i-1][j]==0 || dp[i][j-1]==0)
		dp[i][j]=1;
	else
		dp[i][j]=0;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll i,j;
	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			dp[i][j]=-1,dp[i][j]=-1;
	ll m=sz(s);
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='1')
			dp[0][i+1]=1;
		else
			dp[0][i+1]=0;
	}
	cin>>s;
	ll n=sz(s);
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='1')
			dp[i+1][0]=1;
		else
			dp[i+1][0]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			func(i,j);
	dp[0][0]=2;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}