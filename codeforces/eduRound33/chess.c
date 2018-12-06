#include<stdio.h>

int main()
{
	int n,i;
	int winner;
	int loser;
	int spect=3;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(i!=0)
		{
			spect=loser;
		}
		scanf("%d",&winner);
		if(winner==spect)
		{
			printf("NO\n");
			return 0;
		}
		if(winner==1 && spect==2)
			loser=3;
		if(winner==1 && spect==3)
			loser=2;
		if(winner==2 && spect==1)
			loser=3;
		if(winner==2 && spect==3)
			loser=1;
		if(winner==3 && spect==1)
			loser=2;
		if(winner==3 && spect==2)
			loser=1;
	}
	printf("YES\n");
	return 0;
}