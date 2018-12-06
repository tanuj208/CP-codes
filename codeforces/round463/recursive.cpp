#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll g(ll n)
{
	if(n<10)
		return n;
	ll temp=n;
	ll digit=1;
	ll x;
	while(temp!=0)
	{
		x=temp%10;
		if(x==0)
			x=1;
		digit*=x;
		temp/=10;
	}
	return g(digit);
}

ll value[1000001][11];
// ll ccount[1000001];

int main()
{
	ll q;
	cin>>q;
	ll i,j;
	ll number[14]={0};
	for(i=1;i<=1000000;i++)
	{
		number[g(i)]++;
		for(j=1;j<=9;j++)
			value[i][j]=number[j];
		// ccount[i]=number[value[i]];
	}
	// cout<<value[22][9]<<" "<<value[73][9]<<endl;
	while(q--)
	{
		ll l,r,k;
		cin>>l>>r>>k;
		ll ans=value[r][k]-value[l][k];
		if(g(l)==k)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}