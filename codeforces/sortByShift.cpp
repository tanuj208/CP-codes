#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	int i,value;
	for(i=0;i<n;i++)
	{
		cin>>value;
		arr.push_back(value);
	}
	arr.push_back(1000000);
	int foundMinElement=0;
	int x=n;
	for(i=0;i<n;i++)
	{
		if(foundMinElement==1 && (arr[i]>arr[i+1] || arr[n-1]>arr[0]))
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(arr[i]<=arr[i+1])
			continue;
		else
		{
			x=i+1;
			foundMinElement=1;
		}
	}
	cout<<n-x<<endl;
	return 0;
}