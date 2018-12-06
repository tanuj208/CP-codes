#include<stdio.h>

int main()
{
	int n,a[100000],m,i;
	long long time;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m-1;i++)
	{
		if(a[i+1]-a[i]>=0)
			time+=a[i+1]-a[i];
		else
			time+=(n+a[i+1]-a[i]);
	}
	time+=a[0]-1;
	printf("%I64d\n",time);
	return 0;
}


