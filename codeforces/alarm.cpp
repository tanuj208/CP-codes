#include <iostream>

int main()
{
	int n,m,k;
	std::cin>>n>>m>>k;
	int alarm[500000];
	int hash[1000005]={0};
	int i;
	for(i=0;i<n;i++)
	{
		std::cin>>alarm[i];
		hash[alarm[i]]=1;
	}
	int l=0;
	int r;
	int ans=0;
	int count=0;
	for(r=0;r<1000008;r++)
	{
		if(hash[r]==1)
			count++;
		if(r-l<m && count>=k)
		{
			hash[r]=0;
			count--;
			ans++;
		}
		if(r-l==m-1)
		{
			if(hash[l]==1)
				count--;
			l++;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}