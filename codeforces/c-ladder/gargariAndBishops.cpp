#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	ll chess[2005][2005];
	ll aa[5000],bb[5000];
	ll i,j;
	ll money[2005][2005];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>chess[i][j];
			aa[i+j]+=chess[i][j];
			bb[n+(i-j)]+=chess[i][j];
		}
	}
	ll x,y;
	ll max=0;
	ll max1=0;
	ll w,z;
	ll t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			t=aa[i+j]+bb[i-j+n]-chess[i][j];
			if((i+j)%2==0)
			{
				if(max<=t)
				{
					max=t;
					x=i;
					y=j;
				}
			}
			else
			{
				if(max1<=t)
				{
					max1=t;
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