#include<stdio.h>

int main()
{
	int n,i,m,k,j,count,friend=0,a[1001];
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(((a[m]>>j)%2)!=((a[i]>>j)%2))
				count++;
		}
		if(count<=k)
			friend++;
	}
	printf("%d\n",friend);
	return 0;
}


