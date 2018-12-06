#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll max(ll a, ll b)
{
	if(a>b)
		return a;
	else
		return b;
}

// int answer(int index)
// {
// 	if(index>n)
// 	{
// 		return 0;
// 	}
// 	if(index==n)
// 	{
// 		ll x=(ll)hash[index]*(ll)index;
// 		return x;
// 	}
// 	ll points1=0;
// 	ll points2=0;
// 	// cout<<"y";
// 	if(dp[index+2]==-1)
// 	{
// 		dp[index+2]=answer(index+2);
// 	}
// 	points1+=(ll)hash[index]*(ll)index+dp[index+2];
// 	if(dp[index+3]==-1)
// 	{
// 		dp[index+3]=answer(index+3);
// 	}
// 	points2+=(ll)hash[index+1]*(ll)(index+1)+dp[index+3];
// 	if(points2>=points1)
// 		return points2;
// 	else
// 		return points1;
// }

int main()
{
	ll hash[100005];
	ll n;
	ll dp[100005];
	cin>>n;
	ll i;
	for(i=0;i<100005;i++)
	{
		dp[i]=-1;
	}
	ll value;
	for(i=0;i<n;i++)
	{
		cin>>value;
		hash[value]++;
	}
	dp[100000]=100000*hash[100000];
	dp[100001]=0;
	dp[99999]=max((99999)*hash[99999],100000*hash[100000]);
	for(i=99998;i>=1;i--)
	{
		dp[i]=max(i*hash[i]+dp[i+2],(i+1)*hash[i+1]+dp[i+3]);
	}
	cout<<dp[1]<<endl;
	return 0;
}