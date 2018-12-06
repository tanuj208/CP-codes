#include<stdio.h>

int main()
{
	int n,tens,ones;
	scanf("%d",&n);
	ones=-n%10;
	tens=(-n%100)/10;
	if(n>=0)
		printf("%d",n);
	else
		if(tens<=ones)
			printf("%d",-(-n-ones)/10);
		else
			printf("%d",-(((-n-(10*tens))/10)+ones));
	return 0;
}


