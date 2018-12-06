#include<stdio.h>

int main()
{
	int n;
	int i,l[1000005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&l[i]);
	int killed=l[n-1];
	if(l[n-1]>=n-1 || n==1)
	{
		printf("1\n");
		return 0;
	}
	int x=l[n-1];
	int w=0;
	for(i=n-2;i>=0;i--)
	{
//		if(x-w>=i+1)
//		{
//			killed+=i+1;
//			break;
//		}
		if(x-w==0)
		{
			if(l[i]>=i)
			{
				killed=killed+i;
				break;
			}
			killed+=l[i];
			x=l[i];
			w=0;
			continue;
		}
		if(l[i]>=x-w)
		{
			if(l[i]>=i)
			{
				killed=killed+i-x+w+1;
				break;
			}
			killed+=l[i]-x+w+1;
			w=0;
			x=l[i];
			continue;
		}
		w++;
	}
	printf("%d\n",n-killed);
	return 0;
}


