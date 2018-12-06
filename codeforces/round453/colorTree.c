#include <stdio.h>

int edge[10005];
int color[10005];
int n;
int step;

int f(int vx)
{	
	int i; 
	for(i=2;i<=n;i++)
	{
		if(edge[i]==vx)
		{
			if(color[i]==color[vx])
			{
				f(i);
			}
			else
			{
				step++;
				f(i);
			}
		}
	}
	return step;
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=2;i<n+1;i++)
	{
		scanf("%d",&edge[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&color[i]);
	}
	step=1;
	printf("%d\n",f(1));
	return 0;
}