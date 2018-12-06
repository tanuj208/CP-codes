#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

ll val(char c)
{
	return (ll)c-ll('a');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	if(sz(s)<4)
	{
		cout<<"No\n";
		return 0;
	}
	map<ll,ll> x;
	ll i;
	for(i=0;i<sz(s);i++)
	{
		if(x.find(val(s[i]))==x.end())
			x.insert(mp(val(s[i]),1));
		else
			x[val(s[i])]++;
	}
	if(sz(x)>4 || sz(x)==1)
	{
		cout<<"No\n";
		return 0;
	}
	if(sz(x)==3 || sz(x)==4)
	{
		cout<<"Yes\n";
		return 0;
	}
	if(sz(x)==2)
	{
		auto it=x.begin();
		if((*it).second==1)
		{
			cout<<"No\n";
			return 0;
		}
		it++;
		if((*it).second==1)
		{
			cout<<"No\n";
			return 0;
		}
		cout<<"Yes\n";
		return 0;
	}

	return 0;
}