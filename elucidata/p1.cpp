#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<char, int> roman_to_num;
	roman_to_num['I']=1;
	roman_to_num['V']=5;
	roman_to_num['X']=10;
	roman_to_num['L']=50;
	roman_to_num['C']=100;
	roman_to_num['D']=500;
	roman_to_num['M']=1000;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ans=0;
		int i;
		// main logic is if a bigger roman number comes after a smaller one, then the smaller one contributes to substraction else to addition
		for(i=(int)s.size()-1;i>=0;i--)
		{
			char c=s[i];
			if(i==(int)s.size() - 1)
				ans+=roman_to_num[c];
			else
			{
				int x1=roman_to_num[c];
				int x2=roman_to_num[s[i+1]];
				if(x1<x2)
					ans-=x1;
				else
					ans+=x1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}