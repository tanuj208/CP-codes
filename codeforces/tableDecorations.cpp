#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll arr[5];
	cin>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	ll maxTables=0;
	ll x=(arr[0]+arr[1]+arr[2])/3;
	if(arr[2]<=2*(arr[1]+arr[0]))
	{
		cout<<x<<endl;
		return 0;
	}
	else
	{
		cout<<x-(arr[2]-2*(arr[1]+arr[0]))/3<<endl;
		return 0;
	}
	// cout<<arr[0]<<arr[1]<<arr[2];
	return 0;
}