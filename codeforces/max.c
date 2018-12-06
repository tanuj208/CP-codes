#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int matrix[100005][11];

int min(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int comp(const void * aa, const void * bb)
{
	char * a = (char *) aa;
	char * b = (char *) bb;
	int lena=strlen(a);
	int lenb=strlen(b);
	int i;
	for(i=0;i<min(lena,lenb);i++)
	{
		if(a[i]>b[i])
			return 1;
		if(a[i]<b[i])
			return 0;
	}
	if(lena<lenb)
		return 1;
	else
		return 0;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",matrix[i]);
	qsort(matrix,n,11 * sizeof(char),comp);
	for(i=0;i<n;i++)
		printf("%d",matrix[i]);
	return 0;
}
