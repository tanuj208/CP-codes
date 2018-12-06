#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
	return ( *(int*)a-*(int*)b);
}
int main()
{
	int n,m,k,i;
	scanf("%d %d %d",&n,&m,&k);
	int alarm[200005];
	for(i=0;i<n;i++)
		scanf("%d",&alarm[i]);
	qsort(alarm,n,sizeof(int),cmp);
	//alarm array is now sorted
	int j=0;
	// for(i=0;i<n;i++)
	// 	printf("%d ",alarm[i]);
	// printf("\n");
	return 0;
}


