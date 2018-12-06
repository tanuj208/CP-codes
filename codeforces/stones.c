#include<stdio.h>

int main()
{
	int n,i,count=0;
	char color[50];
	scanf("%d\n %s",&n,&color[1]);
	for(i=1;i<n;i++)
	{
		if(color[i]==color[i+1])
			count++;
	}
	printf("%d",count);
	return 0;
}


