#include<stdio.h>

int main()
{
	int a1, a2, a3, b1, b2, b3, n, cups, medals;
	scanf("%d %d %d\n %d %d %d\n %d",&a1, &a2, &a3, &b1, &b2, &b3, &n);
	cups=(a1+a2+a3+4)/5;
	medals=(b1+b2+b3+9)/10;
	if(cups+medals>n)
		printf("NO\n");
	else 
		printf("YES\n");
	return 0;
}


