#include<stdio.h>
int n;

int inc(int start, int arr[])
{
	int i;
	for(i=start+1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
			return i-1;
	}
	return -1;
}

int dec(int start, int arr[])
{
	int i;
	for(i=start+1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
			return i-1;
	}
	return -1;
}

int main()
{
	int i;
	int a[100003];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int x;
	x=inc(0,a);
//	printf("%d\n",x);
	if(x==-1)
	{
		printf("yes\n1 1\n");
		return 0;
	}
	int y;
		y=dec(x,a);
//		printf("%d\n",y);
	if(y==-1 && a[n-1]>a[x-1])
	{
		printf("yes\n%d %d\n",x+1,n);
		return 0;
	}
	if(x!=0 && y!=n-1)
	{
		if(a[x]>a[y+1] || a[x-1]>a[y])
		{
			printf("no\n");
			return 0;
		}
	}
	if(x==0 && y!=n-1)
	{
		if(a[x]>a[y+1])
		{
			printf("no\n");
			return 0;
		}
	}
	if(y==n-1 && x!=0)
	{
		if(a[x-1]>a[y])
		{
			printf("no\n");
			return 0;
		}
	}
	if(y==n-1 && x==0)
	{
		if(a[x]>a[y])
		{
			printf("no\n");
			return 0;
		}
	}
	if(inc(y+1,a)==-1)
	{
		printf("yes\n%d %d\n",x+1,y+1);
		return 0;
	}
	printf("no\n");
//	printf("%d\n",inc(0,a));
//	printf("%d\n",dec(0,a));
	return 0;
}
