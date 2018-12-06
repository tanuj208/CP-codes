#include<stdio.h>
int arr[10000],crr[10000];
int merge(int l, int r, int mid)
{
	int a=l;
	int b=mid+1;
	int c=0;
	int coun=0,i;
	while(a<=mid && b<=r)
	{
		if(arr[a]<=arr[b])
		{
			crr[c]=arr[a];
			c++;
			a++;
		}
		else
		{
			crr[c]=arr[b];
			c++;
			b++;
			coun+=mid+1-a;
		}
	}
	while(a<=mid)
	{
		crr[c]=arr[a];
		c++;
		a++;
	}
	while(b<=r)
	{
		crr[c]=arr[b];
		c++;
		b++;
	}
	for(i=0;i<r;i++)
		arr[i+l]=crr[i];
	return coun;
}
int count(int l, int r)
{
	int mid=(l+r)/2;
	count(l,mid);
	count(mid+1,r);
	merge(l,r,mid);
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int a=count(0,n-1);
	printf("%d",a);
	return 0;
}
