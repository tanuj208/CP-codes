#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,sum=0,k,a[1005],i;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("%d\n",(abs(sum)+k-1)/k);
	return 0;
}
	
