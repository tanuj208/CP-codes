#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll i;
	ll x=1,y=1;
	ll flag=0;
	for(i=1;i<k;i++)
	{
		cout<<"2 ";
		cout<<x<<" "<<y<<" ";
		if(flag==0)
		{
			y++;
		}
		if(flag==1)
		{
			y--;
		}
		if(y==m+1 && flag==0)
		{
			y=m;
			x++;
			flag=1;
		}
		if(y==0 && flag==1)
		{
			y=1;
			x++;
			flag=0;
		}
		cout<<x<<" "<<y<<endl;
		if(flag==0)
		{
			y++;
		}
		if(flag==1)
		{
			y--;
		}
		if(y==m+1 && flag==0)
		{
			y=m;
			x++;
			flag=1;
		}
		if(y==0 && flag==1)
		{
			y=1;
			x++;
			flag=0;
		}
	}
	ll s=(n*m)-(2*(k-1));
	cout<<s<<" ";
	for(i=1;i<=s;i++)
	{
		cout<<x<<" "<<y<<" ";
		if(flag==0)
		{
			y++;
		}
		if(flag==1)
		{
			y--;
		}
		if(y==m+1 && flag==0)
		{
			y=m;
			x++;
			flag=1;
		}
		if(y==0 && flag==1)
		{
			y=1;
			x++;
			flag=0;
		}
	}
	cout<<endl;
	return 0;
}