#include<stdio.h>

int main()
{
	int m,n,a,area,ar,ans;
	printf("m=");
	scanf("%d\n",&m);
	printf("n=");
	scanf("%d\n",&n);
	printf("a=");
	scanf("%d\n",&a);
        area=m*n;
        ar=a*a;
	if (m%a==0,n%a==0)
	{
		printf("%d\n",ans=area/ar);
	}
	if ( m%a==0)
	{
		printf("%d\n",ans=area/ar+m/a);
	}
	if ( n%a==0)
	{
		printf("%d\n",ans=area/ar+n/a);
	}
	else
	{
		printf("%d\n",ans=area/ar+m/a+n/a);
	}

	return 0;
}


