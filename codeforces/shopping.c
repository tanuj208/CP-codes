#include<stdio.h>

int main()
{
	int d1,d2,d3,a,b,c,d;
	scanf("%d %d %d",&d1,&d2,&d3);
	a=2*(d1+d2);
	b=d1+d2+d3;
	c=2*(d1+d3);
	d=2*(d2+d3);
	if(a<=b && a<=c && a<=d)
		printf("%d",a);
	else if(b<=a && b<=c && b<=d)
		printf("%d",b);
	else if(c<=a && c<=b && c<=d)
		printf("%d",c);
	else if(d<=a && d<=b && d<=c)
		printf("%d",d);
	return 0;
}


