#include<stdio.h>

int main()
{
	long long int x, a, b, c, d;
	scanf("%I64d", &x);
	a=x%5;
	b=a%4;
	c=b%3;
	d=c%2;
	printf("%I64d\n",((x/5)+(a/4)+(b/3)+(c/2)+(d/1)));
	return 0;
}


