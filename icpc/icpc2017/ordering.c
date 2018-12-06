#include<stdio.h>

int check(int arr1[],int arr2[])
{
	if(arr1[0]==arr2[0] && arr1[1]==arr2[1] && arr1[2]==arr2[2])
		return 0;
	if(arr1[0]>=arr2[0] && arr1[1]>=arr2[1] && arr1[2]>=arr2[2])
		return 1;
	else if(arr1[0]<=arr2[0] && arr1[1]<=arr2[1] && arr1[2]<=arr2[2])
		return 1;
	else
		return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a[3],b[3],c[3];
		int i;
		for(i=0;i<3;i++)
			scanf("%d",&a[i]);
		for(i=0;i<3;i++)
			scanf("%d",&b[i]);
		for(i=0;i<3;i++)
			scanf("%d",&c[i]);
		if(check(a,b)==1 && check(b,c)==1 && check(a,c)==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}


