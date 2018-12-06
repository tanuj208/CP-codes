#include<stdio.h>
int main()
{
	int n, i, j, ans;
	scanf("%d",&n);
	ans=(n*n+1)/2;
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
			for(j=1;j<=n;j++)
			{
				if(j%2==0)
					printf("C");
				else
					printf(".");
			}
		else
			for(j=1;j<=n;j++)
			{
				if(j%2==0)
					printf(".");
				else
					printf("C");
			}
		printf("\n");
	}
	return 0;
}
