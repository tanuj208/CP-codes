#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int i;
	if(n<m)
	{
		cout<<n+1<<endl;
		for(i=0;i<=n;i++)
		{
			cout<<i<<" "<<i+1<<endl;
		}
	}
	if(n>m)
	{
		cout<<m+1<<endl;
		for(i=0;i<=m;i++)
		{
			cout<<i+1<<" "<<i<<endl;
		}
	}
	if(n==m)
	{
		cout<<n+1<<endl;
		for(i=0;i<=n;i++)
		{
			cout<<i<<" "<<n-i<<endl;
		}
	}
	return 0;
}