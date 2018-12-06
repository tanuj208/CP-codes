#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	int teleportStart[1000];
	int teleportEnd[1000];
//	std::cout<<"HFD";
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&teleportStart[i],&teleportEnd[i]);
	}
//	std::cout<<"HFD";
	int flag=0;
	int max=0;
	int k;
	for(i=0;i<n;i++)
	{
		if(teleportStart[i]==0)
		{
			if(max<teleportEnd[i])
			{
				max=teleportEnd[i];
				k=i;
			}
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("NO\n");
		return 0;
	}
	if(teleportEnd[k]>=m)
	{
		printf("YES\n");
		return 0;
	}
	int j=0;
//	printf("%d\n",teleportEnd[k]);
	int temp;
	while(teleportEnd[k]<m && flag!=0)
	{
//	printf("T\n");
		flag=0;
		temp=teleportEnd[k];
		for(j=0;j<n;j++)
		{
			if(teleportStart[j]<=temp)
			{
				if(max<teleportEnd[j])
				{
					flag=1;
					max=teleportEnd[j];
					k=j;
				}
			}
		}
	}
	if(flag==1 || teleportEnd[k]>=m)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}