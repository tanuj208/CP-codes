#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> numbers;
	int input;
	int i;
	long long totalSum=0;
	int flagg=0;
	for(i=0;i<n;i++)
	{
		cin>>input;
		if(input!=0)
			flagg=1;
		totalSum+=input;
		numbers.push_back(input);
	}
	long long x=(long long)(n-1)*(long long)(n-2)/2;
	if(flagg==0)
	{
		cout<<x<<endl;
		return 0;
	}
	if(totalSum%3!=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	long long sum=totalSum/3;
	long long ans=0;
	int j=1;
	i=0;
	long long a=0;
	long long b=0;
	int flag=0;
	long long tempans=0;
	while(i<=n-3)
	{
		a+=numbers[i];
		if(a==sum)
		{
			if(flag==1 && numbers[i]==0)
			{
				ans+=tempans;
				i++;
				continue;
			}
			if(flag==1 && numbers[i]!=0)
				flag=0;
			tempans=0;
			flag=1;
			b=0;
			j=i+1;
			while(j<=n-2)
			{
				b+=numbers[j];
				if(b==sum)
				{
					ans++;
					tempans++;
				}
				j++;
			}
		}
		i++;
	}
	cout<<ans<<endl;
	// for(i=0;i<n;i++)
	// {
	// 	cout<<numbers[i]<<" ";
	// }
	// cout<<endl;
	return 0;
}