#include<stdio.h>

int main()
{
	int i,n,h,a[1000],width=0;
	scanf("%d %d\n",&n,&h);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(h>=a[i])
		{
			width++;
		}
		else
		{
			width+=2;
		}
	}
	printf("%d",width);
	return 0;
}


