#include<stdio.h>

int main()
{
	float number;
	float sqrot=2;
	printf("Enter the number ");
	scanf("%f", &number);
	while (number-(sqrot*sqrot)>0.001 || number-(sqrot*sqrot)<-0.001)
	{
		sqrot= (sqrot+(number/sqrot))/2;
	}
	printf("Square root of %f is %f\n", number, sqrot);
	return 0;
}


