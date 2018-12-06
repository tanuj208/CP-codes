#include <stdio.h>

int tensdigit(int num)
{
	num=num/10;
	return num%10;
}

int hundredsdigit(int num)
{
	return num/100;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	if(n<3)
	{
		printf("-1\n");
		return 0;
	}
	if(n==3)
	{
		printf("210\n");
		return 0;
	}
	int numberarray[100004]={0};
	numberarray[0]=1;
	numberarray[n-1]=0;
	int x;
	if(n%6==0)
	{
		x=-100;
	}
	if(n%6==1)
	{
		x=1;
	}
	if(n%6==2)
	{
		x=10;
	}
	if(n%6==3)
	{
		x=100;
	}
	if(n%6==4)
	{
		x=-1;
	}
	if(n%6==5)
	{
		x=-10;
	}
	int decidingNumber,temp;
	int tens,hundreds;
	for(decidingNumber=0;decidingNumber<1000;decidingNumber+=10)
	{
		temp=decidingNumber;
		temp=temp+x;
		if(temp%7!=0)
			continue;
		tens=tensdigit(decidingNumber);
		hundreds=hundredsdigit(decidingNumber);
		if((tens+hundreds+1)%3==0)
			break;
	}
	numberarray[n-2]=tens;
	numberarray[n-3]=hundreds;
	for(i=0;i<n;i++)
		printf("%d",numberarray[i]);
	printf("\n");
	return 0;
}