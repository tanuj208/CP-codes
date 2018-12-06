#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,l;

typedef struct x{
	ll cost;
	ll capacity;
//	double costPerLitre;
}bottle;

bottle lemon[40];

ll answer(ll total)
{
	if(total<=0)
		return 0;
	ll min=LLONG_MAX;
	ll temp=total;
	ll i;
	for(i=0;i<n;i++)
	{
		if(lemon[i].capacity>=total)
		{
			if(min>=lemon[i].cost)
				min=lemon[i].cost;
		}
	}
	ll index=0;
	ll min1=lemon[0].cost;
	ll nm=2;
	for(i=1;i<n;i++)
	{
		if(lemon[i].capacity>=total)
			break;
		if(lemon[i].cost<=min1*nm)
		{
			min1=lemon[i].cost;
			index=i;
			nm=2;
			continue;
		}
		nm=nm*2;
	}	
	// x is number of bottles bought
	ll x=total/lemon[index].capacity;
	// cout<<index<<endl;
	total=total-x*lemon[index].capacity;
	// cout<<total<<endl;
	ll z=x*lemon[index].cost+answer(total);
	// cout<<min<<" "<<z<<endl;
	if(z>=min)
	{
		return min;
	}
	else
	{
		return z;
	}
}

int main()
{
	cin>>n>>l;
	ll i;
	ll size=1;
	ll min=LLONG_MAX;
	for(i=0;i<n;i++)
	{
		cin>>lemon[i].cost;
		if(min>lemon[i].cost)
			min=lemon[i].cost;
		lemon[i].capacity=size;
//		lemon[i].costPerLitre=(lemon[i].cost*1.0/lemon[i].capacity*1.0);
		size*=2;
	}
	// for(i=0;i<n;i++)
	// {
	// 	cout<<lemon[i].cost<<" "<<lemon[i].capacity<<" "<<lemon[i].costPerLitre<<endl;
	// }
	// cout<<endl;
	if(l==1)
	{
		cout<<min<<endl;
		return 0;
	}
	if(n==1)
	{
		cout<<l*lemon[0].cost<<endl;
		return 0;
	}
	cout<<answer(l)<<endl;
	return 0;
}