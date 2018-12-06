#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	string color;
	cin>>color;
	ll flag=0;
	for(ll i=1;i<n;i++)
	{
		if(color[i]=='?')
			flag=1;
		if(color[i]==color[i-1] && color[i]!='?')
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	for(ll i=1;i<n;i++)
	{
		if(color[i]==color[i-1] && color[i]=='?')
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	ll ways=0;
	if(color[0]=='?' || color[n-1]=='?')
	{
		cout<<"Yes\n";
		return 0;
	}
	if(flag==0)
	{
		cout<<"No\n";
		return 0;
	}
	for(ll i=1;i<n-1;i++)
	{
		if(color[i]=='?')
		{
			if(color[i-1]==color[i+1])
			{
				cout<<"Yes\n";
				return 0;
			}
		}
	}
	cout<<"No\n";	
	return 0;
}