#include <stdio.h>
#include <string.h>

int min(int num1, int num2)
{
	if(num1<=num2)
		return num1;
	else
		return num2;
}

int commonDivisors(int num1, int num2)
{
	int i,divisor=0;
	for(i=1;i<=min(num1,num2);i++)
	{
		if(num1%i==0 && num2%i==0)
			divisor++;
	}
	return divisor;
}

int main()
{
	char string1[100005];
	char string2[100005];
	scanf("%s",string1);
	scanf("%s",string2);
	int len1=strlen(string1);
	int len2=strlen(string2);
	int i=0,j=1;
	int commonStringLen1=1,commonStringLen2=1;
	int flag=0;
	//using two pointers for calculating string's divisor's length
	//pointer i remains at start position unless divisor is found or appeared to be found
	//pointer j always increases and is compared with i
	while(j<len1)
	{
		if(flag==0)
		{
			if(string1[i]!=string1[j])
			{
				j++;
				commonStringLen1++;
			}
			else
			{
				j++;
				i++;
				flag=1;
			}
			continue;
		}
		if(flag==1)
		{
			if(string1[i]==string1[j])
			{
				i++;
				j++;
			}
			else
			{
				commonStringLen1+=i;
				flag=0;
				i=0;
			}
			continue;
		}
	}
	if(len1%commonStringLen1!=0)
	{
		commonStringLen1=len1;
	}
	//doing similarly for other string
	i=0,j=1;
	flag=0;
	while(j<len2)
	{
		if(flag==0)
		{
			if(string2[i]!=string2[j])
			{
				j++;
				commonStringLen2++;
			}
			else
			{
				j++;
				i++;
				flag=1;
			}
			continue;
		}
		if(flag==1)
		{
			if(string2[i]==string2[j])
			{
				i++;
				j++;
			}
			else
			{
				commonStringLen2+=i;
				flag=0;
				i=0;
			}
			continue;
		}
	}
	if(len2%commonStringLen2!=0)
		commonStringLen2=len2;
	if(commonStringLen2!=commonStringLen1)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<commonStringLen2;i++)
	{
		if(string1[i]!=string2[i])
		{
			printf("0\n");
			return 0;
		}
	}
	int num1=len1/commonStringLen1;
	int num2=len2/commonStringLen2;
	int ans=commonDivisors(num1,num2);
	printf("%d\n",ans);
	//printf("%d %d\n",commonStringLen1,commonStringLen2);
	return 0;
}