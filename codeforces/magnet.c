#include<stdio.h>

int main()
{
	int n, magnets[100000], i, count = 1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&magnets[i]);
		if(magnets[i-1]!=magnets[i] && i!=0)
			count++;
	}
	printf("%d",count);
	return 0;
}


