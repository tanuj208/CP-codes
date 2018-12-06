#include<stdio.h>

int main()
{
	int i, n, count=0;
	char string[200000];
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%c",&string[i]);
		if(string[i]=='0')
			count++;
	}
	if(count>(n-count))
		printf("%d",((2*count)-n));
	else
		printf("%d",(n-(2*count)));
	return 0;
}


