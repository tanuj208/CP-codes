#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[2005];
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	i=0;
	int firsttwo=-10;
	int nowtwo=-1;
	int maxi=0;
	j=0;
	while(j<n)
	{
		if(firsttwo==-10 && a[j]==2)
			firsttwo=-2;
		if(firsttwo==-2 && a[j]==1)
			firsttwo=j-1;
		if(firsttwo>=0)
		{
			// cout<<j+1<<endl;
			if(nowtwo==-1 && a[j]==2)
				nowtwo=0;
			if(nowtwo==0 && a[j]==1)
			{
				cout<<i+1<<" "<<j<<endl;
				nowtwo=j-1;
				if(maxi<j-i)
					maxi=j-i;
				i=firsttwo+1;
				j=i-1;
				firsttwo=-10;
				nowtwo=-1;
			}
		}
		j++;
	}
	// cout<<i<<endl;
	if(maxi<n-i)
		maxi=n-i;
	cout<<maxi<<endl;
	return 0;
}