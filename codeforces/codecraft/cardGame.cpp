#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int i,value;
	vector<int> a;
	int hash[100005]={0};
	for(i=0;i<n;i++)
	{
		cin>>value;
		a.push_back(value);
		hash[value]++;
	}
	int flag=0;
	for(i=100000;i>=0;i--)
	{
		if(hash[i]%2==1)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"Conan"<<endl;
	}
	else
	{
		cout<<"Agasa"<<endl;
	}
	return 0;
}