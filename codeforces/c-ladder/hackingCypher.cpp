#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	string key;
	ll i;
	ll a,b;
	cin>>key>>a>>b;
	ll remainderA[1000005];
	remainderA[0]=-1;
	ll A=0,B=0;
	ll remainderB[1000005];
	for(i=0;i<(ll)key.length();i++)
	{
		A=(A*10+(key[i]-'0'))%a;
		remainderA[i+1]=A;
	}
	ll ten=1;
	for(i=(ll)(key.length())-1;i>=0;i--)
	{
		B=(B+(ten*(key[i]-'0'))%b)%b;
		remainderB[i]=B;
		ten=(ten*10)%b;
	}
	ll j;
	for(i=0;i<(ll)key.length();i++)
	{
		if(remainderB[i]==0 && remainderA[i]==0 && key[i]!='0')
		{
			cout<<"YES"<<endl;
			for(j=0;j<i;j++)
			{
				cout<<key[j]-'0';
			}
			cout<<endl;
			for(j=i;j<(ll)key.length();j++)
			{
				cout<<key[j]-'0';
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	// for(i=0;i<(ll)key.length();i++)
	// 	cout<<remainderA[i]<<" ";
	// cout<<endl;
	// for(i=0;i<(ll)key.length();i++)
	// 	cout<<remainderB[i]<<" ";
	// cout<<endl;
	return 0;
}