#include<stdio.h>

int main()
{
	long long n,m,min,max;
	scanf("%I64d %I64d",&n,&m);
	max=((n-m+1)*(n-m))/2;
	long long ceil=(n+m-1)/m;
	long long a=(ceil*(ceil-1))/2;
	long long b=((ceil-1)*(ceil-2))/2;
	long long num=(ceil*m)-n;
	min=num*b+(m-num)*a;
	printf("%I64d %I64d\n",min,max);
	return 0;
}


