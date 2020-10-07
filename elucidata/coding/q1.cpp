#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> mul(vector<ll> arr, ll x)
{
	vector<ll> dig;
	while(x>0)
	{
		dig.push_back(x%10);
		x/=10;
	}
	ll i,j;
	vector<ll> finalarr = arr;
	for(i=0;i<finalarr.size();i++)
		finalarr[i]=0;
	ll carry=0;
	for(i=0;i<dig.size();i++)
	{
		ll finIdx = i;
		for(j=0;j<arr.size();j++)
		{
			ll xx = arr[j]*dig[i];
			if(finalarr.size()<finIdx + 1)
				finalarr.push_back(xx);
			else
				finalarr[finIdx]+=xx;
			while(finalarr[finIdx]>=10)
			{
				finalarr[finIdx]-=10;
				if(finalarr.size()<finIdx+2)
					finalarr.push_back(1);
				else
					finalarr[finIdx+1]++;
			}
			finIdx++;
		}
	}
	return finalarr;
}


int main()
{
	vector<ll> arr;
	ll n;
	cin>>n;
	ll i;
	arr.push_back(1);
	for(i=2;i<=n;i++)
	{
		arr=mul(arr, i);
	}
	for(i=arr.size()-1;i>=0;i--)
		cout<<arr[i];
	cout<<endl;
	return 0;
}