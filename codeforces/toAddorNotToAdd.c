#include <stdio.h>

long long integers[100005];

void merge(long long l, long long mid, long long r)
{
	long long a=l;
	long long b=mid+1;
	long long c=0;
	long long arr[100005];
	while(a<=mid && b<=r)
	{
		if(integers[a]<integers[b])
		{
			arr[c]=integers[a];
			c++;
			a++;
		}
		else
		{
			arr[c]=integers[b];
			c++;
			b++;
		}
	}
	while(a<=mid)
	{
		arr[c]=integers[a];
		a++;
		c++;
	}
	while(b<=r)
	{
		arr[c]=integers[b];
		c++;
		b++;
	}
	long long i;
	for(i=0;i<c;i++)
	{
		integers[l+i]=arr[i];
	}
	return;
}

void sort(long long l, long long r)
{
	if(l!=r)
	{
		long long mid=(l+r)/2;
		sort(l,mid);
		sort(mid+1,r);
		merge(l,mid,r);
	}
	return;
}

int main()
{
	long long n,k;
	scanf("%lld %lld",&n,&k);
	long long i;
	for(i=0;i<n;i++)
		scanf("%lld",&integers[i]);
	//using mergesort
	sort(0,n-1);
	long long differenceArray[100005];
	for(i=0;i<n-1;i++)
	{
		differenceArray[i]=integers[i+1]-integers[i];
	}
	long long count=1;
	long long maxcount=1;
	long long number;
	for(i=0;i<n-1;i++)
	{
		if(integers[i]==integers[i+1])
		{
			count++;
		}
		else
		{
			if(maxcount<count)
			{
				maxcount=count;
				number=integers[i];
			}
			count=1;
		}
	}
	long long sum=0;
	long long sum1=0;
	long long j;
	long long temp;
	long long temp2;
	for(i=1;i<n;i++)
	{
		count=1;
		sum1+=differenceArray[i-1];
		sum+=i*differenceArray[i-1];
		temp=sum1;
		temp2=sum;
		j=0;
		while(temp2>k && j<i)
		{
			temp2=temp2-temp;
			temp=temp-differenceArray[j];
			j++;
		}
		count+=i-j;
//		printf("%d\n",count);
		if(maxcount<count)
		{
			maxcount=count;
			number=integers[i];
		}
	}
	printf("%lld %lld\n",maxcount,number);
	// for(i=0;i<n;i++)
	// 	printf("%d ",integers[i]);
	// printf("\n");
	return 0;
}
