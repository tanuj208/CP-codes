#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	ll i,arr[200005];
	for(i=0;i<n;i++)
		cin>>arr[i];
	string all;
	cin>>all;
	ll j;
	for(i=0;i<n;)
	{
		if(all[i]=='0')
			i++;
		else
		{
			j=i+1;
			while(all[j-1]!='0' && j<n)
				j++;
			sort(arr+i,arr+j);
			i=j;
		}
	}
	for(i=0;i<n;i++)
	{
		// cout<<arr[i]<<" ";
		if(arr[i]!=i+1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	// cout<<endl;
	cout<<"YES"<<endl;
	return 0;
}