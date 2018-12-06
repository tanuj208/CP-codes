#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	ll fib=1;
	ll a=1;
	ll i;
	ll temp;
	for(i=1;i<=n;i++)
	{
		if(i==fib)
		{
			cout<<"O";
			temp=fib;
			fib+=a;
			a=temp;
		}
		else
		{
			cout<<"o";
		}
	}
	cout<<endl;
	return 0;
}