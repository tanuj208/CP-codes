#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll fours=0;
	ll sevens=n/7;
	ll temp=n;
	ll i;
	while(temp%7!=0 && temp>0)
	{
		fours++;
		temp-=4;
		sevens=temp/7;
	}
	if(temp%7!=0 || temp<0)
		cout<<"-1\n";
	else
	{
		for(i=0;i<fours;i++)
			cout<<"4";
		for(i=0;i<sevens;i++)
			cout<<"7";
		cout<<endl;
	}
	return 0;
}