#include<stdio.h>

int main()
{
	int n,l,a[1000],i,j;
	scanf("%d %d",&n,&l);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	int diff,max=0;
	for(i=0;i<n-1;i++)
	{
		diff=a[i+1]-a[i];
		if(max<diff)
			max=diff;
	}
	double ans;
	if(max>=2*a[0] && max>=2*(l-a[n-1]))
		ans=(max*(1.0))/2;
	else if(2*a[0]>=max && a[0]>=(l-a[n-1]))
		ans=(a[0]*1.0);
	else if(2*(l-a[n-1])>=max && l-a[n-1]>=a[0])
		ans=(l-a[n-1])*1.0;
	printf("%.10lf\n",ans);
	return 0;
}


