#include <bits/stdc++.h>

using namespace std;

int main()
{
	int p,q,l,r;
	cin>>p>>q>>l>>r;
	int i;
	int count[1005]={0};
	vector<int> c;
	vector<int> d;
	int value;
	int value1;
	int j;
	for(i=0;i<p;i++)
	{
		cin>>value;
		cin>>value1;
		for(j=value;j<=value1;j++)
		{
			count[j]=1;
		}
	}
	for(i=0;i<q;i++)
	{
		cin>>value;
		c.push_back(value);
		cin>>value;
		d.push_back(value);
	}
	int time,flag;
	int answer=0;
	for(time=l;time<=r;time++)
	{
		for(i=0;i<q;i++)
		{
			flag=0;
			for(j=c[i]+time;j<=d[i]+time;j++)
				count[j]++;
			// for(j=0;j<=10;j++)
			// 	cout<<count[j]<<" ";
			// cout<<endl;
			for(j=0;j<1005;j++)
			{
				if(count[j]>1)
				{
					flag=1;
					answer++;
					break;
				}
			}
			for(j=c[i]+time;j<=d[i]+time;j++)
				count[j]--;
			if(flag==1)
				break;
		}
	}
	cout<<answer<<endl;
	return 0;
}