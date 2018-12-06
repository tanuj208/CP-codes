#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int perfect(ll x)
{
	ll sum=0;
	ll temp=x;
	while(temp!=0)
	{
		sum+=temp%10;
		temp/=10;
	}
	if(sum==10)
		return 1;
	else
		return 0;
}

int main()
{
	ll k;
	cin>>k;
	ll count=0,i;
	for(i=1;i<=100000000;i++)
	{
		if(perfect(i)==1)
			count++;
		if(count==k)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	// cout<<perfect(118)<<endl;
	return 0;
}