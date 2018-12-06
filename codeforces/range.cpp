#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,arr[100005];
	cin>>n;
	int i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	int hash[100005]={0};
	int min=arr[0];
	int max=arr[0];
	int lptr=0;
	int j;
	int maxlength=0;
	hash[arr[0]]++;
	for(i=1;i<n;i++)
	{
		hash[arr[i]]++;
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(arr[i]<min)
		{
			min=arr[i];
		}
		// cout<<min<<" "<<max<<endl;
		if(max-min>1)
		{
			if(maxlength<i-lptr)
				maxlength=i-lptr;
			hash[arr[lptr]]--;
			if(hash[arr[lptr]]==0)
			{
				j=arr[lptr];
				// cout<<hash[4]<<hash[5]<<hash[6]<<hash[7]<<endl;
				while(hash[j]==0 && j<=arr[lptr]+5)
					j++;
				// cout<<j<<endl;
				if(arr[lptr]==min)
					min=j;
				j=arr[lptr];
				while(hash[j]==0 && j>=arr[lptr]-5)
					j--;
				if(arr[lptr]==max)
					max=j;
			}
			lptr++;
		}
	}
	// cout<<n-lptr<<endl;
	if(maxlength<n-lptr)
		maxlength=n-lptr;
	cout<<maxlength<<endl;
}