#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int i,a[100005];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int distinct=0;
	int hash[100005]={0};
	for(i=0;i<n;i++)
	{
		hash[a[i]]++;
		if(hash[a[i]]==1)
		{
			distinct++;
		}
		if(distinct==k)
			break;
	}
	if(distinct<k)
	{
		cout<<"-1 -1"<<endl;
		return 0;
	}
	int j=i;
	i=0;
	// cout<<hash[a[0]]<<endl;
	while(hash[a[i]]!=1)
	{
		// cout<<" h"<<endl;
		hash[a[i]]--;
		i++;
	}
	cout<<i+1<<" "<<j+1<<endl;
	return 0;
}