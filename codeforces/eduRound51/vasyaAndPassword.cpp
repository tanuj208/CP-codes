#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,i;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll l=0,u=0,d=0;
		ll indl, indu, indd;
		for(i=0;i<sz(s);i++)
		{
			if(s[i]>='a' && s[i]<='z')
			{
				l++;
				indl=i;
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				u++;
				indu=i;
			}
			else if(s[i]>='0' && s[i]<='9')
			{
				d++;
				indd=i;
			}
		}
		if(l!=0 && u!=0 && d!=0)
		{
			cout<<s<<"\n";
			continue;
		}
		if(d==0 && l!=0 && u!=0)
		{
			if(l>=2)
				s[indl]='1';
			else
				s[indu]='1';
			cout<<s<<"\n";
			continue;
		}
		else if(d!=0 && l==0 && u!=0)
		{
			if(d>=2)
				s[indd]='a';
			else
				s[indu]='a';
			cout<<s<<"\n";
			continue;
		}
		else if(d!=0 && l!=0 && u==0)
		{
			if(d>=2)
				s[indd]='A';
			else
				s[indl]='A';
			cout<<s<<"\n";
			continue;
		}
		else if(d==0 && l==0)
		{
			s[0]='1';
			s[1]='a';
			cout<<s<<"\n";
			continue;
		}
		else if(d==0 && u==0)
		{
			s[0]='A';
			s[1]='1';
			cout<<s<<"\n";
			continue;
		}
		else if(u==0 && l==0)
		{
			s[0]='A';
			s[1]='a';
			cout<<s<<"\n";
			continue;
		}
	}
	return 0;
}