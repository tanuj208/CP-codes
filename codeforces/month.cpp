#include <iostream>

int main()
{
	int n,i,months[55];
	std::cin>>n;
	for(i=0;i<n;i++)
		std::cin>>months[i];
	int nrmlleapnrmlnrml[50]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	int nrmlnrmlnrmlleap[50]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
	int j=0;
	int k;
	int flag1,flag2=0;
	for(j=0;j<48;j++)
	{
		k=j;
		flag1=0;
		for(i=0;i<n;i++)
		{
			if(months[i]!=nrmlnrmlnrmlleap[k])
			{
				flag1=1;
				break;
			}
			k++;
		}
		if(flag1==0)
		{
			flag2=1;
			break;
		}
	}
	for(j=0;j<48;j++)
	{
		flag1=0;
		k=j;
		for(i=0;i<n;i++)
		{
			if(months[i]!=nrmlleapnrmlnrml[k])
			{
				flag1=1;
				break;
			}
			k++;
		}
		if(flag1==0)
		{
			flag2=1;
			break;
		}
	}
	if(flag2==1)
		std::cout<<"Yes"<<std::endl;
	else
		std::cout<<"No"<<std::endl;
	return 0;
}