#include<stdio.h>
int chess[1000][1000];
int check(int chess[][1000], int i,int j,int n)
{
	int a,b;
	for(a=i-1;a>=0;a--)
		if(chess[a][j]==1)
			return 0;
	for(a=i-1,b=j-1;a>=0 && b>=0;a--,b--)
		if(chess[a][b]==1)
			return 0;
	for(a=i-1,b=j+1;a>=0 && b<n;a--,b++)
		if(chess[a][b]==1)
			return 0;

	return 1;
}

int board(int n,int chess[][1000],int row)
{
	int i;
	if(row<n-1)
	{
		for(i=0;i<n;i++)
		{
			if(check(chess, row,i,n)==1)
			{
				chess[row][i]=1;
				if(board(n,chess,row+1)==1)
					return 1;
				else
					chess[row][i]=0;
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(check(chess, row,i,n)==1)
			{
				chess[row][i]=1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			chess[i][j]=0;
	if(board(n,chess,0)==0)
		printf("Not Possible");
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d",chess[i][j]);
			printf("\n");
		}
	}
	return 0;
}
