#include <iostream>

int main()
{
	int n;
	std::cin>>n;
	std::cout<<n<<std::endl;
	int i;
	int ans=-1;
	if(n%2==0)
		ans=1;
	for(i=0;i<=n;i++)
	{
		std::cout<<ans<<" ";
		ans*=-1;
	}
	std::cout<<std::endl;
	std::cout<<n-1<<std::endl;
	ans=1;
	for(i=0;i<n;i++)
	{
		std::cout<<ans<<" ";
	}
	std::cout<<std::endl;
	return 0;
}