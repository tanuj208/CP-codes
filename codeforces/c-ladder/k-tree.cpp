#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k,d;
ll mod=1000000007;
vector< vector<ll> > dp(105, vector<ll>(5,-1));

//if atleast one d length edge is used then flag=1
ll numberOfPaths(ll remainingSum, ll flag)
{
	ll paths=0;
	if(remainingSum<0 || (remainingSum<d && flag==0))
		return 0;
	if(remainingSum==0)
		return 1;
	if(dp[remainingSum][flag]!=-1)
		return dp[remainingSum][flag];
	ll i;
	if(flag==0)
	{
		for(i=1;i<=k;i++)
		{
			if(i<d)
			{
				paths=(paths+numberOfPaths(remainingSum-i,0))%mod;
			}
			else
			{
				paths=(paths+numberOfPaths(remainingSum-i,1))%mod;
			}
		}
		dp[remainingSum][flag]=paths;
	}
	else
	{
		for(i=1;i<=k;i++)
		{
			paths=(paths+numberOfPaths(remainingSum-i,flag))%mod;
		}
		dp[remainingSum][flag]=paths;
	}
	return dp[remainingSum][flag];
}

int main()
{
	cin>>n>>k>>d;
	if(n<d)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<numberOfPaths(n,0)%mod<<endl;
	return 0;
}