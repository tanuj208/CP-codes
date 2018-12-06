#include<bits/stdc++.h>

using namespace std;

typedef struct inte
{
	int a;
	int b;
}interval;

vector<interval> f;

int cmp(interval aa, interval bb)
{
	if(aa.a<bb.a)
	{
		return true;
	}
	if(aa.a>bb.a)
	{
		return false;
	}
	if(aa.a==bb.a)
	{
		if(aa.b<bb.b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int i;
	interval value;
	for(i=0;i<n;i++)
	{
		int aaa;
		cin>>aaa;
		value.a=aaa;
		cin>>aaa;
		value.b=aaa;
		f.push_back(value);
	}
	sort(f.begin(),f.end(),cmp);
	// for(i=0;i<n;i++)
	// {
	// 	cout<<f[i].a<<" "<<f[i].b<<endl;
	// }
	int examtaken=0;
	for(i=0;i<n;i++)
	{
		if(examtaken<=f[i].b)
		{
			examtaken=f[i].b;
		}
		else
		{
			examtaken=f[i].a;
		}
	}
	cout<<examtaken<<endl;
	return 0;
}