#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	// cout<<setprecision(6);
	ll n,m;
	cin>>n>>m;
	double a,b;
	double price;
	ll i;
	double mina=INT_MAX;
	double minb=INT_MAX;
	double min=INT_MAX;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		// cout<<a/b<<endl;
		price=a/b;
		if(price<=min)
		{
			mina=a;
			minb=b;
			min=price;
		}
	}
	printf("%0.20f\n",(mina*m)/(minb));
	// cout<<(double)((double)(a*m)/(double)(b))<<endl;
	// cout<<(float)((float)5/(float)3)<<endl;
	return 0;
}