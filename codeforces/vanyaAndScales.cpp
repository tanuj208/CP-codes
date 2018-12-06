#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll w,m;

void answer(ll x)
{
	if(x==0)
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	if(x%w==0)
		answer(x/w);
	if((x+1)%w==0)
		answer((x+1)/w);
	if((x-1)%w==0)
		answer((x-1)/w);
	cout<<"NO"<<endl;
	exit(0);
}

int main()
{
	cin>>w>>m;
	if(w==2 || m==1 || m==w)
	{
		cout<<"YES"<<endl;
		return 0;	
	}
	answer(m);
	return 0;
}