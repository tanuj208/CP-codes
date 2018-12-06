#include<stdio.h>
#include<string.h>

char s[1000],t[1000];

int valid(int count[])
{
	int i;
	int len=strlen(t);
	int counting[300]={0};
	int len1=strlen(s);
	for(i=0;i<len1;i++)
	{
		counting[t[i]]++;
	}
	for(i=0;i<len;i++)
	{
		if(count[t[i]]<counting[t[i]])
			return 0;
	}
	return 1;
}

int main()
{
	int i;
	scanf("%[^\n]s",s);
	scanf("\n");
	scanf("%[^\n]s",t);
	int count[300]={0};
	int lens=strlen(s);
	for(i=0;i<lens;i++)
	{
		count[s[i]]++;
		if(valid(count)==1)
			break;
	}
	if(valid(count)==0)
	{
		printf("-1\n");
		return 1;
	}
	int j=0;
	int minlen=i+1;
	int w=1;
	int min;
	int len[1000]={0};
	int start[1000];
	int end[1000];
	len[0]=minlen;
	start[0]=0;
	end[0]=i;
	while(j<lens)
	{
		if(i==lens-1 && valid(count)==0)
			break;
		if(valid(count)==1)
		{
			count[s[j]]--;
			j++;
			minlen--;
			if(valid(count)==1)
			{
				len[w]=minlen;
				start[w]=j;
				end[w]=i;
				w++;
			}
			continue;
		}
		if(valid(count)==0)
		{
			i++;
			minlen++;
			count[s[i]]++;
			if(valid(count)==1)
			{
				len[w]=minlen;
				start[w]=j;
				end[w]=i;
				w++;
			}
			continue;
		}
	}
	int k;
	min=len[0];
	for(i=1;i<w;i++)
	{
		if(min>=len[i])
		{
			min=len[i];
			k=i;
		}
	}
	for(i=start[k];i<=end[k];i++)
		printf("%c",s[i]);
	printf("\n");
	return 0;
}
