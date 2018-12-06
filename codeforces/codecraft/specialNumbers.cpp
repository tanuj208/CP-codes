#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod=1000000007;
ll dp[1005][1005];

ll ncr(ll n, ll r)
{
	if(dp[n][r]!=-1)
		return dp[n][r];
	if(r==0 || r==n)
	{
		dp[n][r]=1;
		return dp[n][r];
	}
	if(r==1 || r==n-1)
	{
		dp[n][r]=n;
		return dp[n][r];
	}
	if(r>n)
	{
		dp[n][r]=0;
		return dp[n][r];
	}
	dp[n][r]=(ncr(n-1,r)+ncr(n-1,r-1))%mod;
	return dp[n][r];
}

ll dp2[1005];

ll operations(ll x)
{
	if(dp2[x]!=-1)
		return dp2[x];
	if(x==1)
	{
		dp2[x]=0;
		return dp2[x];
	}
	ll temp=x;
	ll ones=0;
	while(temp>0)
	{
		if(temp%2==1)
			ones++;
		temp/=2;
	}
	dp2[x]=1+operations(ones);
	return dp2[x];
}

int main()
{
	ll i,j;
	for(i=0;i<1005;i++)
	{
		for(j=0;j<1005;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(i=0;i<1005;i++)
		dp2[i]=-1;
	string n;
	cin>>n;
	ll k;
	cin>>k;
	if(k==0	)
	{
		cout<<"1"<<endl;
		return 0;
	}
	auto len=n.length();
	ll answer=0;
	//j denotes number of ones
	for(j=1;j<=(ll)len;j++)
	{
		// cout<<ncr(i,j)<<endl;
		if(operations(j)==k-1)
		{
			answer=(answer+ncr((ll)len,j))%mod;
		}
	}
	// cout<<len<<endl;
	ll one=0;
	for(i=0;i<(ll)len;i++)
	{
		if(n[i]=='1')
		{
			one++;
			continue;
		}
		else
		{
			one++;
			// cout<<answer<<endl;
			for(j=0;j<=(ll)len-i-1;j++)
			{
				if(operations(one+j)==k-1)
				{
					// cout<<len-i-1<<endl;
					answer=(answer-(ncr((ll)len-i-1,j)%mod)+mod)%mod;
				}
			}
			// cout<<answer<<endl;	
			one--;
		}
	}
	if(k==1)
	{
		cout<<answer-1<<endl;
		return 0;
	}
	cout<<answer<<endl;
	return 0;
}