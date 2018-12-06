#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	cin>>a;
	string b;
	int i;
	for(i=0;i<(int)a.length();i++)
	{
		b.push_back(a[(int)a.length()-i-1]);
	}
	cout<<a<<b<<endl;
	return 0;
}