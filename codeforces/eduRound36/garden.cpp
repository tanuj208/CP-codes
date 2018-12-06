#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int i,value,max=0;
	for(i=0;i<n;i++)
	{
		cin>>value;
		if(k%value==0)
		{
			if(max<value)
				max=value;
		}
	}
	cout<<k/max<<endl;
	return 0;
}