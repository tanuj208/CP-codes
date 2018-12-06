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
		string s1,s2,s3,s4;
		cin>>s1>>s2;
		if(s1[0]=='0' || s2[0]=='0')
			s1[0]='1',s2[0]='1';
		else
			s1[0]='0',s2[0]='0';
		for(i=1;i<sz(s1);i++)
		{
			if(s1[i]=='0' || s1[i-1]=='0')
				s1[i]='1';
			else
				s1[i]='0';
		}
		for(i=1;i<sz(s2);i++)
		{
			if(s2[i]=='0' || s2[i-1]=='0')
				s2[i]='1';
			else
				s2[i]='0';
		}
		s3=s1;
		s4=s2;
		s1[0]=s2[1];
		s2[0]=s1[1];
		if(s1[0]=='0' || s2[0]=='0')
			s1[1]='1',s2[1]='1';
		else
			s1[1]='0',s2[1]='0';
		for(i=2;i<sz(s1);i++)
		{
			if(s1[i]=='0' || s1[i-1]=='0')
				s1[i]='1';
			else
				s1[i]='0';
		}
		for(i=2;i<sz(s2);i++)
		{
			if(s2[i]=='0' || s2[i-1]=='0')
				s2[i]='1';
			else
				s2[i]='0';
		}
		ll q;
		cin>>q;
		while(q--)
		{
			ll x,y;
			cin>>x>>y;
			if(x<=2 || y<=2)
			{
				if(x==2)
					cout<<s1[y-1];
				else if(y==2)
					cout<<s2[x-1];
				else if(x==1)
					cout<<s3[y-1];
				else if(y==1)
					cout<<s4[x-1];
			}
			else if(x<=y)
				cout<<s1[y-(x-2)-1];
			else if(x>y)
				cout<<s2[x-(y-2)-1];
		}
		cout<<"\n";
	}
	return 0;
}