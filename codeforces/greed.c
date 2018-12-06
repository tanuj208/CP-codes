#include<stdio.h>

int main()
{
	int n,a[100006],b[100006];
	scanf("%d",&n);
	int i;
	long long sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	long long max=0;
	int l;
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]>max)
		{
			max=b[i];
			l=i;
		}
	}
	b[l]=0;
	long long max2=0;
	for(i=0;i<n;i++)
		if(b[i]>max2)
			max2=b[i];
	if(sum>max+max2)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}


