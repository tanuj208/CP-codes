#include<stdio.h>

int main()
{
	int t,n,lap[101];
	scanf("%d",&t);
	int i;
	while(t--)
	{
		scanf("%d",&n);
		int count[101]={0};
		for(i=0;i<n;i++)
		{
			scanf("%d",&lap[i]);
			count[lap[i]]++;
		}
		for(i=0;i<101;i++)
		{
			if(count[i]==1)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}


