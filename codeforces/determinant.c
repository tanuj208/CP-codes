#include<stdio.h>

//function to calculate determinant of a given matrix and its no of rows
int det(int matt[][20],int n)
{
	int mat1[20][20];
	int sum=0;
	int row,col;
	int i,j,k;
	if(n>1)
	{
		for(i=0;i<n;i++)
		{
			row=0;
			col=0;
			for(j=1;j<n;j++)
			{
			//j for row of original determinant
			//first row is not added in smaller determinant
				for(k=0;k<n;k++)
				//k for column of original determinant
				{
					if(k!=i)
					//ith column is not added in smaller determinant
					{
						if(col==n-1)
						//since no of rows and columns in smaller determinant is n-1 so next row is used when column index reaches to n-2
						{
							col=0;
							row++;
						}
						mat1[row][col]=matt[j][k];
						col++;
						int l,m;
					}
				}
			}
			int l,m;
			if(i%2==0)
				sum+=(matt[0][i]*det(mat1,n-1));
			else
				sum-=(matt[0][i]*det(mat1,n-1));
		}
		return sum;
	}
	else
		return matt[0][0];
}

int main()
{
	int n;
	scanf("%d",&n);
	int mat[20][20];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	}
	int ans=det(mat,n);
	printf("%d\n",ans);
	return 0;
}
