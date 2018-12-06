#include<bits/stdc++.h>
using namespace std;

int main()
{
	char string[1002];
	scanf("%s",string);
	long long len=strlen(string);
	long long k;
	cin>>k;
	long long w[28];
	long long i;
	for(i=97;i<=123;i++)
		cin>>w[i];
	long long answer=0;
	for(i=0;i<len;i++)
	{
		answer+=(i+1)*w[string[i]];
	}
	long long max=0;
	for(i=97;i<124;i++)
	{
		if(max<w[i])
			max=w[i];
	}
	for(i=1;i<=k;i++)
	{
		answer+=(len+i)*max;
	}
	cout<<answer<<endl;
	return 0;
}


