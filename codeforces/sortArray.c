#include<stdio.h>

int main()
{
	int n,i;
	int a[100005];
	scanf("%d",&n);
	int flag1=0;
	int flag2=0;
	int flag3=0;
	int x,y;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n>2)
	{
		for(i=1;i<n;i++)
		{
			if(a[i]<=a[i-1] && flag1==0)
			{
				flag1=1;
				x=i-1;
				continue;
			}
			else if(a[i]>=a[i-1] && flag1==0)
				continue;
			if(a[i]>=a[i-1] || i==n-1)
			{
				if(flag2==0)
				{
					flag2=1;
					y=i-1;
					continue;
				}
			}
			else if(a[i]<=a[i-1] && flag2==0)
				continue;
			if(a[x]>a[y] || a[x-1]>a[y-1])
			{
				printf("no\n");
				return 0;
			}
			if(a[i]<a[i-1] && i!=y)
			{
				printf("no\n");
				return 0;
			}
		}
		if(y==n-1)
			printf("yes\n%d %d\n",x+1,y+1);
		else
			printf("yes\n%d %d\n",x+1,y);
	}
	else if(n==2)
	{
		if(a[1]>=a[0])
			printf("no\n");
		else
			printf("yes\n0 1\n");
	}
	else if(n==1)
	{
		printf("no\n");
	}
	return 0;
}


