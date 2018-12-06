#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll seats[2001][2001];

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll i,j;
	ll free=0;
	for(i=0;i<n;i++)
	{
		string x;
		cin>>x;
		for(j=0;j<m;j++)
		{
			if(x[j]=='*')
				seats[i][j]=1;
			if(x[j]=='.')
			{
				seats[i][j]=0;
				free++;
			}
		}
	}
	if(k==1)
	{
		cout<<free<<endl;
		return 0;
	}
	ll zeros=0;
	ll ans=0;
	for(i=0;i<n;i++)
	{
		zeros=0;
		for(j=0;j<m;j++)
		{
			if(seats[i][j]==0)
				zeros++;
			else
			{
				if(zeros>=k)
					ans+=zeros-k+1;
				zeros=0;
			}
			if(j==m-1)
				if(zeros>=k)
					ans+=zeros-k+1;
			// cout<<zeros<<endl;
		}
	}
	for(i=0;i<m;i++)
	{
		zeros=0;
		for(j=0;j<n;j++)
		{
			if(seats[j][i]==0)
				zeros++;
			else
			{
				if(zeros>=k)
					ans+=zeros-k+1;
				zeros=0;
			}
			if(j==n-1)
				if(zeros>=k)
					ans+=zeros-k+1;
		}
	}
	// if(k==1)
	// {
	// 	cout<<ans/2<<endl;
	// 	return 0;
	// }
	cout<<ans<<endl;	
}