#include <stdio.h>

int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int moneyleft=n;
	while(moneyleft>=0)
	{
		moneyleft-=a;
	}
	moneyleft+=a;
	if(moneyleft==0)
	{
		printf("YES\n");
		printf("%d 0\n",(n/a));
		return 0;
	}
//	printf("%d\n",moneyleft);
	int firstcan=n/a;
	int secondcan=0;
	while(firstcan>=0 && secondcan<=n/b)
	{
		if(moneyleft==0)
		{
			printf("YES\n");
			printf("%d %d\n",firstcan,secondcan);
			return 0;
		}
		if(moneyleft>=b)
		{
			moneyleft-=b;
			secondcan++;
		}
		else
		{
			moneyleft+=a;
			firstcan--;
		}
	}
	printf("NO\n");
	return 0;
}