#include<stdio.h>

int main()
{
	long long int n;
	scanf("%I64d",&n);
	printf("%I64d\n", ((n*(n*n+5))/6));
	return 0;
}


