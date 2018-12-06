#include<stdio.h>

int main()
{
	int n, i, first, last, middle, search, array[100];
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter the number\n");
	scanf("%d",&search);
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	first=0;
	last=(n-1);
	middle=((n-1)/2);
	while(search!=array[middle])
	{
		middle=(first+last)/2;
		if(search>array[middle])
		{
			first=middle+1;
		}
		else if(search<array[middle])
		{
			last=middle-1;
		}
	}
	printf("%d is at %d place in the array\n",search,(middle+1));
	return 0;
}


