#include <bits/stdc++.h>

using namespace std;

int main()
{
	string word;
	vector<int> number;
	vector<char> alp;
	cin>>word;
	int count=1;
	auto it=word.begin();
	for(it=word.begin();it!=word.end()-1;it++)
	{
		if(*it==*(it+1))
		{
			count++;
		}
		else
		{
			number.push_back(count);
			// cout<<*it<<endl;
			alp.push_back(*it);
			// cout<<count<<endl;
			count=1;
		}
	}
	number.push_back(count);
	alp.push_back(*it);
	// cout<<*(it)<<endl;
	auto it1=number.begin();
	for(it1=number.begin();it1!=number.end();it1++)
	{
		if(*it1>=3)
		{
			*it1=2;
		}
	}
	int flag=0;
	for(it1=number.begin();it1!=number.end();it1++)
	{
		// cout<<*it1<<endl;
		if(*it1==2 && flag==0)
		{
			flag=1;
			continue;
		}
		if(*it1==2 && flag==1)
		{
			// cout<<"j";
			*it1=1;
			flag=0;
		}
		if(*it1==1)
			flag=0;
	}
	// for(it1=number.begin();it1!=number.end();it1++)
	// {
	// 	cout<<*it1<<" ";
	// }
	// cout<<endl;
	int i=0;
	for(it1=number.begin();it1!=number.end();it1++)
	{
		// cout<<endl<<alp[i]<<endl;
		if(*it1==1)
		{
			cout<<alp[i];
		}
		else
		{
			cout<<alp[i]<<alp[i];
		}
		i++;
	}
	cout<<endl;
	return 0;
}