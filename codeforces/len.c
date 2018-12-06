#include<stdio.h>

int main()
{
	int m,i,s;
	scanf("%d %d",&m,&s);
	if(s==0 && m==1)
	{
		printf("0 0\n");
		return 0;
	}
	if(s==0 || s>(9*m))
	{
		printf("-1 -1\n");
		return 0;
	}
	int temp=s;
	int flag=0;
	int num[101];
	for(i=0;i<m;i++)
	{
		if(temp==0)
		{
			num[i]=0;
			continue;
		}
		if(temp-1<=9*(m-i-1) && flag==0)
		{
			num[i]=1;
			temp-=1;
			flag=1;
			continue;
		}
		if(temp<=9*(m-i-1))
		{
			num[i]=0;
			continue;
		}
		if(temp>9*(m-i-1))
		{
			num[i]=temp-9*(m-i-1);
			temp=9*(m-i-1);
			continue;
		}
		num[i]=9;
	}
	for(i=0;i<m;i++)
		printf("%d",num[i]);
	printf(" ");
	for(i=0;i<m;i++)
	{
		if(s>=9)
		{
			num[i]=9;
			s-=9;
			continue;
		}
		if(s<9 && s!=0)
		{
			num[i]=s;
			s=0;
			continue;
		}
		if(s==0)
		{
			num[i]=0;
			continue;
		}
		num[i]=0;
	}
	for(i=0;i<m;i++)
		printf("%d",num[i]);
	printf("\n");
	return 0;
}
