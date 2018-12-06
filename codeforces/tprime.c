#include<stdio.h>
#include<math.h>
long long arr[1000000];
int count;

int search(long long num)
{
	int start=0;
	int end=count-1;
	int mid=(start+end)/2;
	while(mid!=start && mid!=end)
	{
		if(arr[start]==num || arr[end]==num)
			return 1;
		mid=(start+end)/2;
		if(arr[mid]>num)
			end=mid-1;
		if(arr[mid]<num)
			start=mid+1;
		if(arr[mid]==num)
			return 1;
	}
	return 0;
}

int main()
{
	int j;
	long long i;
	arr[0]=4;
	arr[1]=9;
	count=2;
	for(i=5;i<1000000;i++)
	{
		int x=sqrt(i);
		for(j=2;j<=x;j++)
		{
			if(i%j==0)
				break;
		}
		if(j==x+1)
		{
			arr[count]=i*i;
			count++;
		}
	}
//	printf("%d",count);
	int n;
	scanf("%d",&n);
	long long num;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num);
		if(search(num)==1)
			printf("YES\n");
		if(search(num)==0)
			printf("NO\n");
	}
//	for(i=0;i<count;i++)
//		printf("%lld ",arr[i]);
	return 0;
}


