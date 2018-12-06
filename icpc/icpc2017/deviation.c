#include<stdio.h>
#include<math.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a=(n*n*(n-1)*(2*n-1))/6;
	int b=k*k*n*n;
	int c=n*(n-1);
	int d=(n*n*(n-1)*(n-1))/4;
	int A=n-1;
	int B=-c;
	int C=a-b-d;
	float D=sqrt(B*B-(4*A*C));
	float answer=(-B+D)/(2.0*A);
	int i;
	for(i=1;i<n;i++)
		printf("%d ",i);
	printf("%f\n",answer);
	return 0;
}


