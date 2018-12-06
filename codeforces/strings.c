#include<stdio.h>

int main()
{
	int i,sum1,sum2;
	char string1[100],string2[100];
	scanf("%s %s",string1,string2);
	while(string1[i]!='\0')
	{
		if(string1[i]<='z')
		{
			sum1+=string1[i];
			sum2+=string2[i];
		}
		else
		{
			sum1+=string1[i]-32;
			sum2+=string2[i]-32;
		}
	}
	if(sum1<sum2)
	{
		printf("-1");
	}
	else if(sum1==sum2)
	{
		printf("0");
	}
	else
	{
		printf("1");
	}
	return 0;
}


