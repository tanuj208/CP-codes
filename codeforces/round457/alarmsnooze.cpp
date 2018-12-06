#include <bits/stdc++.h>

using namespace std;

int h,m;
int x;

void time()
{
	if(m>=x)
	{
		m=m-x;
		return;
	}
	if(m<x && h!=0)
	{
		m=60-(x-m);
		h--;
		return;
	}
	m=60-(x-m);
	h=23;
	return;
}

int main()
{
	cin>>x;
	int hh,mm;
	cin>>hh>>mm;
	if(hh%10==7 || mm%10==7)
	{
		cout<<"0"<<endl;
		return 0;
	}
	h=hh;
	m=mm;
	int count=0;
	while(1)
	{
		time();
		count++;
		// cout<<h<<" "<<m<<endl;
		if(h%10==7 || m%10==7)
		{
			cout<<count<<endl;
			return 0;
		}
	}
	// cout<<h<<" "<<m<<endl;
	return 0;
}