#include<stdio.h>

int main()
{
	int n,b[1000000],i,j,max,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n-1;i++)
	{
		max=b[i];
		for(j=i;j<n;j++)
		{
			if(b[j]>b[max])
				max=j;
		}
		temp=b[max];
		b[max]=b[i];
		b[i]=temp;
	}
	int diff=b[0]-b[n-1];
	int start=1;
	for(i=0;i<n-1;i++)
	{
		if(b[i]==b[i+1])
			start++;
		else
			break;
	}
	printf("%d",start);
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	int end=1;
	for(i=0;i<n-1;i++)
	{
		if(b[n-1-i]==b[n-2-i])
			end++;
		else
			break;
	}
	printf("%d %d\n",diff,start*end);
	return 0;
}
