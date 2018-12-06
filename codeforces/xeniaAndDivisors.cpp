#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	int value;
	int hasharray[10]={0};
	for(i=0;i<n;i++)
	{
		cin>>value;
		hasharray[value]++;
	}
	// for(i=1;i<=7;i++)
	// 	cout<<hasharray[i]<<" ";
	// cout<<endl;
	if(hasharray[5]>0 || hasharray[7]>0)
	{
		cout<<"-1\n";
		return 0;
	}
	int two=hasharray[2];
	int four=hasharray[4];
	int three=hasharray[3];
	int six=hasharray[6];
	if(hasharray[1]!=n/3)
	{
		cout<<"-1\n";
		return 0;
	}
	else
	{
		while(two!=0 && four!=0)
		{
			two--;
			four--;
		}
		while(two!=0 && six!=0)
		{
			two--;
			six--;
		}
		while(three!=0 && six!=0)
		{
			three--;
			six--;
		}
		if(two>0 || four>0 || three>0 || six>0)
		{
			cout<<"-1\n";
			return 0;
		}
		else
		{
			two=hasharray[2];
			three=hasharray[3];
			four=hasharray[4];
			six=hasharray[6];
			while(two!=0 && four!=0)
			{
				two--;
				four--;
				cout<<"1 2 4\n";
			}
			while(two!=0 && six!=0)
			{
				two--;
				six--;
				cout<<"1 2 6\n";
			}
			while(three!=0 && six!=0)
			{
				three--;
				six--;
				cout<<"1 3 6\n";
			}	
		}
	}
	//possible groups 124 126 136
	return 0;
}







