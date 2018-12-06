#include<stdio.h>
#include<string.h>

int main()
{
	int i, f, n, sum=1;
	char name[100];
	scanf("%s", name);
	n=strlen(name);
	for(i=1; i<n; i++)
	{
		for(f=0; f<i; f++)
		{
			if(name[i]!=name[f])
				sum=sum+1;
		}
	}
	if(sum%2==0)
		printf("CHAT WITH HER!");
	else
		printf("IGNORE HIM!");
	return 0;
}


