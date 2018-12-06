#include <iostream>

using namespace std;

int main()
{
	int zero,one;
	cin>>zero>>one;
	if(one>2+2*zero || one<zero-1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int i;
	int temp0=zero;
	int temp1=one;
	if(one>=2*zero)
	{
		for(i=1;i<=zero;i++)
		{
			cout<<"110";
			temp0--;
			temp1-=2;
		}
		for(i=1;i<=temp1;i++)
		{
			cout<<"1";
		}
		cout<<endl;
		return 0;
	}
	temp1=one;
	temp0=zero;
	if(one>=zero-1 && one<2*zero)
	{
		while(temp1!=2*temp0 && temp0>0 && temp1>0)
		{
			cout<<"01";
			temp1--;
			temp0--;
		}
		if(temp1==0 && temp0==1)
		{
			cout<<"0";
			temp0--;
		}
//		cout<<endl<<temp1<<temp0<<endl;
		for(i=1;i<=temp0;i++)
		{
			cout<<"011";
		}
		cout<<endl;
		return 0;
	}
	return 0;
}