#include<stdio.h>
#include<string.h>
int main()
{
	int i,l,count=0;
	char string[100];
	scanf("%s",string);
	l=strlen(string);
	for(i=0;i<l/2;i++)
	{
		if(string[i]!=string[l-i-1])
		{
			printf("%d ",(i+1));
			string[i]=string[l-i-1];
			count++;
		}
	}
		printf("\n");
	for(i=0;i<l;i++)
		printf("%c",string[i]);
	printf("\n%d\n",count);
	return 0;
}
