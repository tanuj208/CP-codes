#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	// cout<<setprecision(6);
	ll n,m;
	cin>>n>>m;
	ll a,b;
	double price;
	ll i;
	ll mina=INT_MAX;
	ll minb=INT_MAX;
	ll min=INT_MAX;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		// cout<<a/b<<endl;
		price=(double)((double)a/(double)b);
		if(price<=min)
		{
			mina=a;
			minb=b;
			min=price;
		}
	}
	printf("%0.20f\n",(double)((double)(a*m)/(double)(b)));
	// cout<<(double)((double)(a*m)/(double)(b))<<endl;
	// cout<<(double)((double)5/(double)3)<<endl;
	return 0;
}