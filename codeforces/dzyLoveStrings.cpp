#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	vector<int> weight;
	int i;
	int value;
	int max=0;
	for(i=0;i<26;i++)
	{
		cin>>value;
		if(max<value)
			max=value;
		weight.push_back(value);
	}
	int currentWeight=0;
	int len=s.length();
	int x,y;
	for(i=0;i<len;i++)
	{
		x=s[i];
		y='a';
		currentWeight+=(i+1)*weight[x-y];
	}
	while(i<len+k)
	{
		currentWeight+=(i+1)*max;
		i++;
	}
	cout<<currentWeight<<endl;
	return 0;
}