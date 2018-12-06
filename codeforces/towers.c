#include<stdio.h>

int indexMax[10000];
int indexMin[10000];
int htMax=0;
int htMin=10000;

//function that stores max and min values and their respective indexes of the array in global variables
void Ht(int len, int arr[], int x)
{
	htMax=0;
	htMin=10000;
	int i;
	for(i=0;i<len;i++)
	{
		if(arr[i]>htMax)
		{
			htMax=arr[i];
			indexMax[x]=i;
		}
		if(arr[i]<htMin)
		{
			htMin=arr[i];
			indexMin[x]=i;
		}
	}
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int i,ht[1000];
	for(i=0;i<n;i++)
		scanf("%d",&ht[i]);
	int min=10000;
	int instability;
	i=0;
	while(i<=k)
	{
		Ht(n,ht,i);
//				printf("%d %d\n",indexMax[i],indexMin[i]);
		instability=htMax-htMin;
		if(min>=instability)
			min=instability;
		else
			break;
		if(indexMin[i]==indexMax[i])
			break;
		if(i!=k)
		{
			ht[indexMax[i]]--;
			ht[indexMin[i]]++;
			//		for(k=0;k<n;k++)
			//			printf("%d ",ht[k]);
			//		printf("\n");
		}
			i++;
	}
//	i--;
//	if(i<0)
//		i=0;
	printf("%d %d\n",min,i);
	int j;
	for(j=0;j<i;j++)
		printf("%d %d\n",indexMax[j]+1,indexMin[j]+1);
//	for(j=0;j<n;j++)
//		printf("%d ",ht[i]);
	return 0;
}


