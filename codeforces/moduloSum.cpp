#include <bits/stdc++.h>

using namespace std;

int num[1000005];
int dp[1005][1005];
int n,m;

int check(int ptr,int rsum)
{
	if(rsum==0)
	{
		return 1;
	}
	if(ptr>=n)
	{
		return 0;
	}
	if(rsum<0)
	{
		rsum+=m;
	}
	if(dp[ptr+1][rsum-num[ptr]]==-1)
		dp[ptr+1][rsum-num[ptr]]=check(ptr+1,rsum-num[ptr]);
	if(dp[ptr+1][rsum]==-1)
		dp[ptr+1][rsum]=check(ptr+1,rsum);
	return (dp[ptr+1][rsum-num[ptr]] | dp[ptr+1][rsum]);
}

int main()
{
	ios_base:: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	int i,j;
	for(i=0;i<1005;i++)
	{
		for(j=0;j<1005;j++)
			dp[i][j]=-1;
	}
	for(i=0;i<n;i++)
	{
		cin>>num[i];
		num[i]%=m;
	}
	if(n>m)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(num[i]==0)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	if(check(0,m)==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}