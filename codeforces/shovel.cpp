#include <iostream>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	if(n<5)
	{
		cout<<((n-1)*n)/2<<endl;
		return 0;
	}
	long long l;
	if(n>=5 && n<50)
		l=1;
	if(n>=50 && n<500)
		l=10;
	if(n>=500 && n<5000)
		l=100;
	if(n>=5000 && n<50000)
		l=1000;
	if(n>=50000 && n<500000)
		l=10000;
	if(n>=500000 && n<5000000)
		l=100000;
	if(n>=5000000 && n<50000000)
		l=1000000;
	if(n>=50000000 && n<500000000)
		l=10000000;
	if(n>=500000000 && n<5000000000)
		l=100000000;
	if(n>=5000000000)
		l=1000000000;
	long long i=0;
	long long k=(10*l)*((n/(5*l))-i)-1;
//	cout<<k<<endl;
	long long temp=n;
	long long ans=0;
	while(temp>=0)
	{
		k=(10*l)*((n/(5*l))-i)-1;
		if(temp>=k)
			temp=k-1;
		if(temp<0)
			break;
		ans+=temp+1-((5*l)*((k/(10*l))+1));
		i++;
	}
	cout<<ans<<endl;
	return 0;
}