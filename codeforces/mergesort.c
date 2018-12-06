#include<stdio.h>
int arr[1000],crr[1000];
void merge (int l, int r, int mid)
{
	int i;
	int a=l;
	int b=mid+1;
	int c=0;
	while(a<=mid && b<=r)
	{
		if(arr[a]>arr[b])
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
		}
	}
	while(a<=mid)
	{
		crr[c]=arr[a];
		a++;
		c++;
	}
	while(b<=r)
	{
		crr[c]=arr[b];
		b++;
		c++;
	}
	for(i=0;i<c;i++)
		arr[i+l]=crr[i];
}
void sort (int l,int r) 
{
	if(l<r)
	{
		int mid=(l+r)/2;
		sort(l,mid);
		sort(mid+1,r);
		merge (l,r,mid);
	}
}

int main()
{
	int n,op;
	scanf("%d",&n);
	for(op=0;op<n;op++)
		scanf("%d",&arr[op]);
	sort (0,n-1);
	for(op=0;op<n;op++)
		printf("%d ",arr[op]);
	return 0;
}


