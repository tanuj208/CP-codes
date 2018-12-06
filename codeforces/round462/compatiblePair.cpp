#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n,m;
	cin>>n>>m;
	ll a[100],b[100];
	ll i;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
		cin>>b[i];
	ll j;
	ll mm=0;
	ll m2=LLONG_MAX;
	for(mm=0;mm<n;mm++)
	{
		ll m1=-LLONG_MAX;
		for(i=0;i<n;i++)
		{
			if(i==mm)
				continue;
			for(j=0;j<m;j++)
				m1=max(m1,a[i]*b[j]);
		}
		m2=min(m2,m1);
	}
	cout<<m2<<endl;
	return 0;
}