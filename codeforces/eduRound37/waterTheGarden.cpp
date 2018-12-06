#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll time=1,val,preval=0;
		ll i;
		ll x;
		for(i=0;i<k;i++)
		{
			cin>>val;
			if(preval==0)
			{
				time=val;
			}
			else
			{
				if((val-preval)%2!=0)
					x=(val-preval-1)/2+1;
				else
					x=(val-preval-1)/2+2;
				if(time<x)
					time=x;
			}
			preval=val;
		}
		if(time<n+1-val)
			time=n+1-val;
		cout<<time<<endl;
	}
	return 0;
}