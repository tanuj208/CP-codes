#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> integers;
	int i,value;
	for(i=0;i<n;i++)
	{
		cin>>value;
		integers.push_back(value);
	}
	double x;
	int max=-10000000;
	for(i=0;i<n;i++)
	{
		if(integers[i]<0)
		{
			if(max<integers[i])
			{
				max=integers[i];
				continue;
			}
		}
		x=sqrt(integers[i]);
		if(ceil(x)!=floor(x))
		{
			if(max<integers[i])
			{
				max=integers[i];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}