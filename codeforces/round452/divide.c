#include <stdio.h>

int main()
{
	int n,i,oddarr[100000]={1,2},evenarr[100000]={1};
	scanf("%d",&n);
	int big=0;
	int items;
	if(n%2==1)
	{
		items=2;
		for(i=5;i<=n;i+=2)
		{
			if(big==0)
			{
				oddarr[items]=i;
				big=1;
				items++;
			}
			else
			{
				oddarr[items]=i-1;
				big=0;
				items++;
			}
		}
		if(big==1)
			printf("1\n");
		else
			printf("0\n");
		printf("%d ",items);
		for(i=0;i<items;i++)
			printf("%d ",oddarr[i]);
		printf("\n");
	}
	if(n%2==0)
	{
		items=1;
		for(i=4;i<=n;i+=2)
		{
			if(big==0)
			{
				evenarr[items]=i;
				big=1;
				items++;
			}
			else
			{
				evenarr[items]=i-1;
				big=0;
				items++;
			}
		}
		if(big==0)
			printf("1\n");
		else
			printf("0\n");
		printf("%d ",items);
		for(i=0;i<items;i++)
			printf("%d ",evenarr[i]);
		printf("\n");
	}
	return 0;
}
