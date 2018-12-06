#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)

int isvowel(char a)
{
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y')
		return 1;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string str;
	cin>>str;
	int i;
	for(i=0;i<n;i++)
	{
		if(isvowel(str[i])==1 && isvowel(str[i+1])==1)
		{
			str.erase(i+1,1);
			i--;
		}
	}
	cout<<str<<endl;
	return 0;
}
		