#include<stdio.h>
int dp[500];
int k;
int count;
int n;
//defining a function that will tell number of walks needed for nth day
void walk(int r)
{
	int a;
	if(r==0 || r==n-1)
	{
		printf("%d ",dp[r]);
		return;
	}
	if(dp[r]+dp[r-1]<k)
	{
		a=dp[r];
		dp[r]=k-dp[r-1];
	}
	count+=dp[r]-a;
	printf("%d ",dp[r]);
}

int main()
{
	int i;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&dp[i]);
	printf("%d\n",count);
	for(i=0;i<n;i++)
		walk(n);
	printf("\n");
	return 0;
}


