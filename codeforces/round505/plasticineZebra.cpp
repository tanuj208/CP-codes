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
	string s;
	cin>>s;
	ll i;
	ll st=1,m=0,en=1;
	for(i=1;i<sz(s);i++)
	{
		if(s[i]!=s[i-1])
			st++;
		else
			break;
	}
	if(i==sz(s))
	{
		cout<<st<<endl;
		return 0;
	}
	ll sind=i;
	for(i=sz(s)-2;i>=0;i--)
	{
		if(s[i]!=s[i+1])
			en++;
		else
			break;
	}
	ll eind=i;
	ll cnt=1;
	for(i=sind+1;i<=eind;i++)
	{
		if(s[i]!=s[i-1])
			cnt++;
		else
		{
			m=max(m,cnt);
			cnt=1;
		}
	}
	m=max(m,cnt);
	// cout<<m<<endl;
	if(s[0]==s[sz(s)-1])
		cout<<max(st,max(m,en))<<endl;
	else
		cout<<max(st+en,m)<<endl;
	return 0;
}