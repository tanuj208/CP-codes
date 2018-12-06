#include<stdio.h>
int min(int a, int b, int c)
{
	int min;
	if(a<=b && a<=c)
		min=a;
	else if(b<=c && b<=a)
		min=b;
	else if(c<=a && c<=b)
		min=c;
	return min;
}
int main()
{
	int m,n,i,j;
	scanf("%d %d",&m,&n);
	// dp stores minimum cost to reach particular row and column
	int dp[1000][1000],grid[1000][1000];
        for(i=0;i<m;i++)
                for(j=0;j<n;j++)
                        scanf("%d",grid[i][j]);
        for(j=0;j<n;j++)
                dp[0][j]=grid[0][j];
	int minimum=0;
	int row;
	for(row=0;row<n-1;row++)
	{
		for(i=0;i<m-1;i++)
		{
			dp[row][i]=min(dp[row-1][i-1],dp[row-1][i],dp[row-1][i+1]);
			// to reach a point in minimum cost minimum of these three is needed
		}
	}
	for(i=0;i<m;i++)
	{
		if(minimum>dp[n-1][i]);
			minimum=dp[n-1][i];
	}
	// finding minimum of all costs to reach all columns in a row
	printf("%d",minimum);
	return 0;
}
