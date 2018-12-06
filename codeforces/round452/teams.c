#include <stdio.h>

int main()
{
	int n,i,grp[200006];
	scanf("%d",&n);
	int ones=0,twos=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&grp[i]);
//		printf("%d ",grp[i]);
		if(grp[i]==1)
			ones++;
		else
			twos++;
	}
//	printf("%d %d\n",ones,twos);
	if(ones==twos)
	{
		printf("%d\n",ones);
	}
	if(ones>twos)
	{
		printf("%d\n",twos+(ones-twos)/3);
	}
	if(twos>ones)
	{
		printf("%d\n",ones);
	}
	return 0;
}