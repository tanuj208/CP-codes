#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n,a,b;
	cin>>n>>a>>b;
	ll A=0,B=0;
	while(n%b!=0 && n>=0)
	{
		n-=a;
		A++;
	}
	B=n/b;
	if(A<0 || B<0 || n<0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	ll i;
	ll num=1;
	ll j;
	for(i=1;i<=A;i++)
	{
		cout<<num+a-1<<" ";
		for(j=num;j<num+a-1;j++)
			cout<<j<<" ";
		num=num+a;
	}
	for(i=1;i<=B;i++)
	{
		cout<<num+b-1<<" ";
		for(j=num;j<num+b-1;j++)
			cout<<j<<" ";
		num=num+b;
	}
	cout<<endl;
	return 0;
}