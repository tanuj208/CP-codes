#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n,m;
	cin>>n>>m;
	if(n==2)
	{
		cout<<"2"<<" "<<"2"<<endl;
		cout<<"1"<<" "<<"2"<<" "<<"2"<<endl;
		return 0;
	}
	ll i;
	ll flag=0;
	ll j=1;
	for(i=2*(n-2)+2;i<=400000;i++)
	{
		if(i==1)
			i++;
		j=2;
		flag=0;
		while(j<=sqrt(i))
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
			j++;
		}
		if(flag==0)
			break;
	}
	ll x=i-2*(n-2);
	cout<<"2"<<" "<<i<<endl;
	cout<<"1 "<<n<<" 2"<<endl;
	m--;
	for(i=1;i<n-2;i++)
	{
		cout<<i<<" "<<i+1<<" "<<"2"<<endl;
		m--;
	}
	cout<<n-2<<" "<<n-1<<" "<<x<<endl;
	m--;
	// cout<<m<<endl<<endl;
	if(m<=0)
		return 0;
	for(i=1;i<=n-2;i++)
	{
		for(j=i+2;j<=n;j++)
		{
			if(i==1 && j==n)
				break;
			cout<<i<<" "<<j<<" "<<"1000000000"<<endl;
			m--;
			if(m==0)
				return 0;
		}
	}
	if(m>0)
	{
		cout<<n-1<<" "<<n<<" 1000000000"<<endl;
	}
	return 0;
}