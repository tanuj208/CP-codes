#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll calculate(ll c,ll last)
{
	ll num;
	if(c=='d')
		num=10;
	else
		num=26;
	if(last==1)
		return num;
	if(last==2)
		return num*num-num;
	if(last==3)
		return num*num*num-(2*num*num)+num;
	if(last==4)
		return num*num*num*num-(3*num*num*num)+(3*num*num)-num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll ans=1;
	ll i;
	char c=s[0];
	ll last=0;
	for(i=1;i<sz(s);i++)
	{
		if(s[i]!=c)
		{
			ans*=calculate(c,i-last);
			last=i;
		}
		c=s[i];
	}
	ans*=calculate(s[sz(s)-1],sz(s)-last);
	cout<<ans<<endl;
	return 0;
}