#include<stdio.h>
#include<string.h>

char string[1000000];
int len;

int find(int index)
{
	int i;
	for(i=len-1;i>index;i--)
	{
		if(string[i]==string[index])
			return i;
	}
	return 0;
}

int minJumps(int start)
{
	int x=find(start);
	if(start==len-1)
		return 0;
	if(x==0)
		return(minJumps(start+1)+1);
	else
		return(minJumps(x)+1);
}

int main()
{
	scanf("%s",string);
	len=strlen(string);
	int ans=minJumps(0);
	printf("%d\n",ans);
	return 0;
}


