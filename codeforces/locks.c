#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,moves=0;
	char a[1000],b[1000];
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	for(i=0;i<n;i++)
	{
		if(abs(a[i]-b[i])>10-abs(a[i]-b[i]))
			moves+=10-abs(a[i]-b[i]);
		else
			moves+=abs(a[i]-b[i]);
	}
	printf("%d\n",moves);
	return 0;
}


