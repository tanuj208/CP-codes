#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int i;
	int value;
	int hash[1005]={0};
	int arr[1005];
	for(i=2;i<=n;i++)
	{
		cin>>value;
		hash[value]++;
		arr[i]=value;
	}
	if(n==3)
	{
		cout<<"No"<<endl;
		return 0;
	}
	for(i=1;i<=1000;i++)
	{
		if(hash[i]!=0 && hash[i]<3)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	int leaf[1002]={0};
	//if leaf then index 1
	for(i=1;i<=n;i++)
	{
		if(hash[i]==0)
		{
			leaf[i]=1;
		}
	}
	int leaves[1002]={0};
	//denotes number of leaves of vertex i
	for(i=2;i<=n;i++)
	{
		if(leaf[i]==1)
		{
			leaves[arr[i]]++;
		}
	}
	// for(i=1;i<=n;i++)
	// {
	// 	cout<<leaves[i]<<" ";
	// }
	// cout<<endl;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(leaves[i]<3 && leaf[i]==0)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}