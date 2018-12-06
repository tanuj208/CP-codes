#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int i;
	int a,b;
	vector<int> array2;
	int max1=0,max2=0;
	for(i=0;i<n;i++)
	{
		cin>>a;
		cin>>b;
		array2.push_back(b);
		if(a>max1)
		{
			max1=a;
			if(b>max2)
			{
				max2=b;
			}
		}
	}
	int maximum=0;
	for(i=0;i<n;i++)
	{
		if(array2[i]>maximum)
			maximum=array2[i];
	}
	if(maximum==max2)
		cout<<max2<<endl;
	else
		cout<<max1<<endl;
	return 0;
}