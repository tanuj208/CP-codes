#include<stdio.h>
int arr[100000];
int len;

int search(int x)
{
	int l=0,r=len-1,mid;
	while(r>=l)
	{
		mid=(l+r)/2;
		if(x>arr[mid])
			l=mid+1;
		if(x<arr[mid])
			r=mid-1;
		if(x==arr[mid])
			return 1;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int j;
	int num;
	for(i=1;i<=n;i++)
	{
		j=1<<i;
		num=(j-1)*(j/2);
		if(num>n)
			break;
		arr[i-1]=num;
	}
	len=i-1;
	for(i=n;i>0;i--)
	{
		if(n%i==0)
		{
			if(search(i)==1)
			{
				printf("%d\n",i);
				return 0;
			}
		}
	}
	return 0;
}
