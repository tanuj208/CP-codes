#include<stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(i%2==0)
			printf("I love that ");
		else
			printf("I hate that ");
	}
	if(n%2==0)
		printf("I love it\n");
	else
		printf("I hate it\n");
	return 0;
}


