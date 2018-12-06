#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
string s;
ll n;

ll func(char x,char y)
{
	ll moves=0;
	ll i;
	for(i=n-1;i>=0;i--)
	{
		if(s[i]==y)
			break;
	}
	if(i==-1)
		return 1000;
	moves+=n-1-i;
	for(;i<n-1;i++)
		s[i]=s[i+1];
	s[n-1]=y;
	if(s[0]=='0')
	{
		i=0;
		while(s[i]=='0')
		{
			moves++;
			i++;
		}
		s[0]=s[i];
		s[i]='0';
	}
	for(i=n-2;i>=0;i--)
	{
		if(s[i]==x)
			break;
	}
	if(i==-1)
		return 1000;
	moves+=n-2-i;
	if(i==0)
	{
		if(s[1]=='0')
			moves++;
	}
	return moves;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=sz(s);
	ll ans=1000;
	string temp=s;
	if(n==1)
	{
		cout<<"-1\n";
		return 0;
	}
	if(s=="50")
	{
		cout<<"0\n";
		return 0;
	}
	ll x=func('0','0');
	s=temp;
	ans=min(ans,x);

	x=func('2','5');
	ans=min(ans,x);
	s=temp;

	x=func('5','0');
	s=temp;
	ans=min(ans,x);

	x=func('7','5');
	s=temp;
	ans=min(ans,x);

	if(ans>=1000)
		cout<<"-1\n";
	else
		cout<<ans<<endl;
	return 0;
}