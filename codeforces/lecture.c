#include<stdio.h>
#include<string.h>

int stinglenght(char mat[][12],int row)
{
	int len=0;
	int i;
	for(i=0;mat[row][i]!='\0';i++)
		len++;
	return len;
}

int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	char a[3001][12];
	char b[3001][12];
	for(i=0;i<m;i++)
	{
		scanf("%s",a[i]);
		scanf("%s",b[i]);
	}
	char lecture[12];
	for(i=0;i<n;i++)
	{
		scanf("%s",lecture);
		for(j=0;j<m;j++)
		{
			if(strcmp(lecture,a[j])==0)
			{
				if(strlen(a[j])<=strlen(b[j]))
					printf("%s ",a[j]);
				else
					printf("%s ",b[j]);
			}
		}
	}
	printf("\n");
	return 0;
}


