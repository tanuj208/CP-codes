#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int main()
{
	int n;
	int impflag=0;
	int numberOfNames=0;
	scanf("%d",&n);
	char name[25][15];
	//name->x-axis==whose name, y-axis==name
	int amount[25];
	char entries[25][15][15];
	//entries->x-axis==whose number, y-axis==number of numbers, z-axis==entry
	int i,j,m,u;
	for(i=0;i<n;i++)
	{
		scanf("%s %d",name[i],&amount[i]);
		for(j=0;j<amount[i];j++)
		{
			scanf("%s",entries[i][j]);
		}
	}

	//calculating number of unique names
	int arr[100]={0};
	for(i=0;i<n;i++)
	{
		if(arr[i]==2)
			continue;
		arr[i]=1;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(name[i],name[j])==0)
				arr[j]=2;
		}
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]==1)
			numberOfNames++;
	}

	int done[25]={0};
	int flag,mainflag=0;
	char phoneNumber[200][15];
	char finalNumber[200][15];
	int x,k,finalamount;
	int len1,len2;
	int newflag=0;
	for(i=0;i<n;i++)
	//i refers to name
	{
		if(done[i]==1)
			continue;
		x=0;
		for(j=0;j<amount[i];j++)
		//j refers to number of numbers
		{
			newflag=0;
			for(u=0;u<x;u++)
			{
				if(strcmp(phoneNumber[u],entries[i][j])==0)
				{
					newflag=1;
					break;
				}
			}
			u=x;
			if(newflag==0)
			{
				strcpy(phoneNumber[u],entries[i][j]);
				x++;
			}
			//phoneNumber[j]=entries[i][j];
		}


		for(j=i+1;j<n;j++)
		//here j refers to name
		{
			if(strcmp(name[i],name[j])==0)
			{
				for(k=0;k<amount[j];k++)
				//k refers to number of numbers
				{
					newflag=0;
					for(u=0;u<x;u++)
					{
						if(strcmp(phoneNumber[u],entries[j][k])==0)
						{
							newflag=1;
							break;
						}
					}
					u=x;
					if(newflag==0)
					{
						strcpy(phoneNumber[u],entries[j][k]);
						x++;
					}
					//phoneNumber[x+k]=entries[j][k];
				}
				done[j]=1;
			}
		}
		// printf("\n\n\n");
		// for(j=0;j<n;j++)
		// 	printf("%d ",done[j]);
		// printf("\n\n\n");
		 finalamount=0;
		// for(j=0;j<x;j++)
		// 	printf("%s ",phoneNumber[j]);
		// printf("\n");
	//	now phoneNumber matrix contains all numbers of a single person
		for(j=0;j<x;j++)
		{
			mainflag=0;
			for(k=0;k<x;k++)
			{
				flag=0;
				if(j==k)
					continue;
				len1=strlen(phoneNumber[j]);
				len2=strlen(phoneNumber[k]);
				// printf("%d %d\n",len1,len2);
				if(len1>len2)
					continue;
				u=len2-1;
				for(m=len1-1;m>=0;m--)
				{
					//printf("%c\n%c\n",phoneNumber[j][m],phoneNumber[k][u]);
					if(phoneNumber[j][m]!=phoneNumber[k][u])
					{
						flag=1;
						break;
					}
					u--;
				}
				if(flag==0)
				{
					mainflag=1;
					break;
				}
				//when flag==0 then jth number is suffix of kth number
			}
			if(mainflag==0)
			{
				strcpy(finalNumber[finalamount],phoneNumber[j]);
				//finalNumber[finalamount]=phoneNumber[j];
				finalamount++;
			}
		}

		if(impflag==0)
		{
			printf("%d\n",numberOfNames);
			impflag=1;
		}

		printf("%s %d ",name[i],finalamount);
		for(j=0;j<finalamount;j++)
		{
			printf("%s ",finalNumber[j]);
		}
		printf("\n");
		done[i]=1;
	}
	//if done for that particular entry than 1 in that element of done array
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<amount[i];j++)
	// 	{
	// 		printf("%s ",entries[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}
