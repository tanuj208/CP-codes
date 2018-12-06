#include<stdio.h>
int ncr(int n, int r)
{
	if(n>r && r!=0)
		return ncr(n-1,r)+ncr(n-1,r-1);
	else if(n==r || r==0)
		return 1;
	else
		return 0;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int z=ncr(a,b);
	printf("%d\n",z);
	return 0;
}


