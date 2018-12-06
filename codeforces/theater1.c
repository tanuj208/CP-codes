#include<stdio.h>

int main()
{
	int n;
	int m;
	int a;
	int htiles;
	int vtiles;
	int tiles;
	scanf("%d %d %d", &n, &m, &a);
	htiles=(n+a-1)/a;
	vtiles=(m+a-1)/a;
	tiles=htiles*vtiles;
	printf("%d\n",tiles);
	return 0;
}


