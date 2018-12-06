#include<stdio.h>

int main()
{
	int n, i, f, sum=0;
	scanf("%d",&n);
	int p[n],q[n];
	for(i=0; i<n; i++)
		scanf("%d %d", &p[i], &q[i]);
	for(f=0; f<n; f++)
		if(q[f]-p[f]>=2)
			sum=sum+1;
	printf("%d\n", sum);
	return 0;
}


