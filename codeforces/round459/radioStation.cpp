#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<string> name;
	vector<string> ip;
	int i;
	string temp;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		name.push_back(temp);
		cin>>temp;
		ip.push_back(temp);
	}
	string tempip;
	int j;
	for(i=0;i<m;i++)
	{
		cin>>temp;
		cin>>tempip;
		cout<<temp;
		cout<<" "<<tempip;
		cout<<" #";
		tempip=tempip.substr(0,tempip.size()-1);
		for(j=0;j<n;j++)
		{
			if(tempip==ip[j])
			{
				cout<<name[j]<<endl;
			}
		}
	}
	// cout<<name[0];
	return 0;
}