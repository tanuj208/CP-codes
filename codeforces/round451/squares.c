#include <stdio.h>
#include <math.h>

long long diffarray[500005];

long long min(long long a, long long b)
{
	if(a<=b)
		return a;
	else
		return b;
}

void merge(long long l, long long mid, long long r)
{
	long long a=l;
	long long b=mid+1;
	long long c=0;
	long long arr[500005];
	while(a<=mid && b<=r)
	{
		if(diffarray[a]<diffarray[b])
		{
			arr[c]=diffarray[a];
			c++;
			a++;
		}
		else
		{
			arr[c]=diffarray[b];
			c++;
			b++;
		}
	}
	while(a<=mid)
	{
		arr[c]=diffarray[a];
		a++;
		c++;
	}
	while(b<=r)
	{
		arr[c]=diffarray[b];
		c++;
		b++;
	}
	long long i;
	for(i=0;i<c;i++)
	{
		diffarray[l+i]=arr[i];
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
	long long i,n;
	long long candy[500005];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&candy[i]);
	}
	long double root;
	long long count=0;
	long long small,big;
	long long minimum;
	for(i=0;i<n;i++)
	{
		root=sqrt(candy[i]);
		small=floor(root);
		big=ceil(root);
		minimum=min(candy[i]-(small*small),(big*big)-candy[i]);
		if(minimum==0)
			count++;
		diffarray[i]=minimum;
	}
	// for(i=0;i<n;i++)
	// {
	// 	printf("%lld ",diffarray[i]);
	// }
	//  printf("\n");
	long long sum=0;
	// printf("%lld\n",count);
	long long j=0;
	if(count>n/2)
	{
		while(j<n)
		{
			if(diffarray[j]==0 && candy[j]!=0)
			{
				sum+=1;
				count--;
			}
			if(count==n/2)
			{
				printf("%lld\n",sum);
				return 0;
			}
			j++;
		}
		j=0;
		while(j<n)
		{
			if(diffarray[j]==0 && candy[j]==0)
			{
				sum+=2;
				count--;
			}
			if(count==n/2)
			{
				printf("%lld\n",sum);
				return 0;
			}
			j++;
		}
	}
	sort(0,n-1);
	if(count<=n/2)
	{
		for(i=0;i<n/2;i++)
		{
			sum+=diffarray[i];
		}
		printf("%lld\n",sum);
		return 0;
	}
	 return 0;
}