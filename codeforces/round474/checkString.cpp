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
	string s;
	cin>>s;
	ll i;
	ll a=0;
	ll b=0;
	ll c=0;
	if(s[0]!='a')
	{
		cout<<"NO\n";
		return 0;
	}
	ll aover=0;
	ll bover=0;
	for(i=0;i<sz(s);i++)
	{
		if(aover==1 && s[i]=='a')
		{
			cout<<"NO\n";
			return 0;
		}
		if(bover==1 && s[i]=='b')
		{
			cout<<"NO\n";
			return 0;
		}
		if(s[i]=='a')
			a++;
		else
			aover=1;
		if(s[i]=='b')
			b++;
		else if(s[i]!='b' && aover==1)
			bover=1;
		if(s[i]=='c')
			c++;
	}
	if((c!=a && c!=b) || a==0 || b==0 || c==0)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	return 0;
}