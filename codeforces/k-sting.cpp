#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int k,i;
	string s;
	cin>>k>>s;
	vector<int> hash(200,0);
	for(i=0;i<(int)s.length();i++)
	{
		hash[(int)s[i]]++;
	}
	for(i=97;i<123;i++)
	{
		if(hash[i]%k!=0)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	string temps;
	int j;
	for(i=97;i<123;i++)
	{
		if(hash[i]>0)
		{
			for(j=1;j<=hash[i]/k;j++)
				temps+=(char)i;
		}
	}
	// cout<<(int)'a'<<endl;
	for(i=1;i<=k;i++)
	{
		cout<<temps;
	}
	cout<<endl;
	return 0;
}