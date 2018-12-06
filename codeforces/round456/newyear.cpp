#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	ll n,k;
	vector <ll> powers;
	cin>>n>>k;
	if(k==1)
	{
		cout<<n<<endl;
		return 0;
	}
	ll i;
	ll value;
	ll x=1;
	for(i=0;i<65;i++)
	{
		value=x;
		powers.push_back(value);
		x=x*2;
	}
	ll m;
	for(i=0;i<65;i++)
	{
		if(n<powers[i])
		{
			m=i-1;
			break;
		}
	}
	ll maxvalue=powers[m+1]-1;
	cout<<maxvalue<<endl;
	return 0;
}