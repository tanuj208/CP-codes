#include<stdio.h>

int main()
{
	int a,b,i=0;
	scanf("%d %d",&a,&b);
	while(b>=a)
	{
		a*=3;
		b*=2;
		i++;
	}
	printf("%d\n",i);
	return 0;
}


