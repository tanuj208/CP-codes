#include<stdio.h>

int main()
{
	int i,j=0;
	int n,k;
	scanf("%d %d",&n,&k);
	char a[1000005];
	scanf("%s",a);
	i=0;
	int inverted=0;
	int len=0;
	int max=0;
	//inverting b only
	if(n==1 && k==0)
	{
		printf("1\n");
		return 0;
	}
	while(j<n)
	{
		if(a[j]=='a')
		{
			j++;
			len++;
			continue;
		}
		if(a[j]=='b' && inverted<k)
		{
			j++;
			len++;
			inverted++;
			continue;
		}
		if(inverted==k)
		{
			if(max<len)
				max=len;
			if(a[i]=='b')
				inverted--;
			i++;
			len--;
		}
	}
	if(len>max)
		max=len;
	j=0;
	i=0;
	len=0;
	inverted=0;
	//inverting a only
	while(j<n)
	{
		if(a[j]=='b')
		{
			j++;
			len++;
			continue;
		}
		if(a[j]=='a' && inverted<k)
		{
			j++;
			len++;
			inverted++;
			continue;
		}
		if(inverted==k)
		{
			if(max<len)
				max=len;
			if(a[i]=='a')
				inverted--;
			i++;
			len--;
		}
	}
	if(len>max)
		max=len;
	printf("%d\n",max);
	return 0;
}


