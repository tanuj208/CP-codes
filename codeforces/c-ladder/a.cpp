#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	ll chess[2005][2005];
	ll i,j;
	ll val;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>chess[i][j];
		}
	}
	ll money1[2005][2005];
	ll money[2005][2005];
	ll sum=0;
	ll sum1=0;
	for(i=0;i<2*n;i++)
	{
		sum=0;
		sum1=0;
		for(j=0;j<=i;j++)
		{
			if(j>=n)
				break;
			if(i-j>=n)
				goto a;
			sum+=chess[j][i-j];
			a:
			if(n-1-i+j<0)
				continue;
			sum1+=chess[j][n-1-i+j];
		}
		for(j=0;j<=i;j++)
		{
			if(j>=n)
				break;
			if(i-j>=n)
				continue;
			money1[j][i-j]=sum;
		}
		for(j=0;j<=i;j++)
		{
			if(j>=n)
				break;
			if(n-1-i+j<0)
				continue;
			money[j][n-1-i+j]=sum1;
		}
	}
	ll x,y;
	ll max=0;
	ll max1=0;
	ll w,z;
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<n;j++)
			{
				if(j%2==0 && max<=money[i][j]+money1[i][j]-chess[i][j])
				{
					max=money[i][j]+money1[i][j]-chess[i][j];
					x=i;
					y=j;
				}
				if(j%2!=0 && max1<=money[i][j]+money1[i][j]-chess[i][j])
				{
					max1=money[i][j]+money1[i][j]-chess[i][j];
					w=i;
					z=j;
				}
			}
		}
		else
		{
			for(j=0;j<n;j++)
			{
				// if(i==3 && j==0)
				// 	cout<<endl<<max1<<endl<<money[i][j]+money1[i][j]-chess[i][j]<<endl;
				if(j%2==1 && max<=money[i][j]+money1[i][j]-chess[i][j])
				{
					max=money[i][j]+money1[i][j]-chess[i][j];
					x=i;
					y=j;
				}
				if(j%2==0 && max1<=money[i][j]+money1[i][j]-chess[i][j])
				{					
					max1=money[i][j]+money1[i][j]-chess[i][j];
					w=i;
					z=j;
				}
			}
		}
	}
	cout<<max+max1<<endl;
	cout<<x+1<<" "<<y+1<<" "<<w+1<<" "<<z+1<<endl;
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 	{
	// 		cout<<money[i][j]+money1[i][j]-chess[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}