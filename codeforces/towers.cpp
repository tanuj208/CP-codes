#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxindex;
int minindex;
vector<int> height;
int n;

void maxmin()
{
	int max=0;
	int i;
	int min=INT_MAX;
	for(i=0;i<n;i++)
	{
		if(max<height[i])
		{
			max=height[i];
			maxindex=i;
		}
		if(min>height[i])
		{
			min=height[i];
			minindex=i;
		}
	}
	return;
}

int main()
{
	int k;
	cin>>n>>k;
	int i;
	int value;
	int max=0;
	int min=INT_MAX;
	for(i=0;i<n;i++)
	{
		cin>>value;
		if(max<value)
		{
			max=value;
			maxindex=i;
		}
		if(min>value)
		{
			min=value;
			minindex=i;
		}
		height.push_back(value);
	}
	if(n==1)
	{
		cout<<"0 0";
		return 0;
	}
	int range=max-min;
	if(range==0 || range==1)
	{
		cout<<range<<" 0\n";
		return 0;
	}
	vector<int> maxx;
	vector<int> minn;
	for(i=1;i<=k;i++)
	{
		maxx.push_back(maxindex+1);
		minn.push_back(minindex+1);
		height[maxindex]--;
		height[minindex]++;
		maxmin();
		range=height[maxindex]-height[minindex];
		if(range==0 || range==1 || i==k)
			break;
	}
	cout<<range<<" "<<i<<endl;
	for(k=0;k<i;k++)
	{
		cout<<maxx[k]<<" "<<minn[k]<<endl;
	}
	return 0;
}