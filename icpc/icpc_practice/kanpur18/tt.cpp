#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1000][1000];
ll ans[1000];
ll solve(ll x,ll y)
{
	if(2*y>=x)
		return 1;
	if(dp[x][y]!=-1)
		return dp[x][y];
	dp[x][y]=0;
	if(y==0)
	{
		for(ll i=1;i<x;i++)
		{
			dp[x][y]=dp[x][y]|(!solve(x-i,i));
			if(dp[x][y])
			{
				ans[x]=i;
				break;
			}
		}
	}
	else
	{
		for(ll i=1;i<=2*y;i++)
		{
			dp[x][y]=dp[x][y]|(!solve(x-i,i));
			if(dp[x][y]==1)
			{
				break;
			}
		}
	}
	return dp[x][y];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	std::vector<ll> v;
	while(1)
	{
		ll n;
		cin>>n;
		if(n==0)
			break;
		if(n==1)
			cout<<0<<endl;
		else
		{
			solve(n,0);
			cout<<ans[n]<<endl;
		}
	}
	return 0;
}