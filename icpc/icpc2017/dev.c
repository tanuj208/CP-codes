#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		if(n!=1)
		{
			float answer=(n*k*1.0)/(sqrt(n-1));
			for(i=1;i<n;i++)
				printf("0 ");
			printf("%.10f\n",answer);
		}
		if(n==1)
		{
			if(k==0)
				printf("4\n");
			else
				printf("-1\n");
		}
	}
	return 0;
}


