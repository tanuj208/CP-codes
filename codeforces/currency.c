#include<stdio.h>
#include<string.h>

char num[100002];

void swap(int a, int b)
{
	int temp=num[a];
	num[a]=num[b];
	num[b]=temp;
}

int main()
{
	scanf("%s",num);
	int len=strlen(num);
	int i;
	for(i=0;i<len-1;i++)
	{
		if(num[i]%2==0 && num[i]<num[len-1])
		{
			swap(i,len-1);
			printf("%s\n",num);
			return 0;
		}
	}
	for(i=len-2;i>=0;i--)
	{
		if(num[i]%2==0)
		{
			swap(i,len-1);
			printf("%s\n",num);
			return 0;
		}
	}
	if(i==-1)
		printf("-1\n");
	return 0;
}


