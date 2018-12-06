#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll k;
	cin>>k;
	if(k>36)
	{
		cout<<"-1\n";
		return 0;
	}
	ll x=k/2;
	ll i;
	for(i=0;i<x;i++)
		cout<<"8";
	if(k%2==1)
		cout<<"4";
	cout<<endl;
	return 0;
}