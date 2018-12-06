#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll p,k;
	cin>>p>>k;
	// cout<<p%k<<" ";
	ll x;
	ll count=0;
	ll arr[500000];
	while(p>k)
	{
		x=p;
		// cout<<x<<endl;
		if(count%2==1)
			p=p/k+p%k;
		else
			p=p/k;
		arr[count]=x%k;
		count++;
	}
	cout<<count+2<<endl;
	ll i;
	for(i=0;i<count;i++){
		cout<<arr[i]<<" ";
	}
	if(count%2==1)
	{
		cout<<-p+k<<" 1"<<endl;
	}
	return 0;
}