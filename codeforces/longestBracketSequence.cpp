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
	ll ans=0;
	ll substrings=0;
	ll open=0;
	ll x=0;
	ll i;
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='(')
		{
			open++;
			x++;
		}
		else
			x--;
		if(x<0)
		{
			if(ans==2*open)
				substrings++;
			else if(ans<2*open)
				substrings=1;
			ans=max(ans,2*open);
			open=0;
			x=0;
		}
	}
	if(x==0)
	{
		if(ans==2*open)
			substrings++;
		else if(ans<2*open)
			substrings=1;
		ans=max(ans,2*open);
	}
	open=0;
	x=0;
	for(i=sz(s)-1;i>=0;i--)
	{
		if(s[i]==')')
		{
			open++;
			x++;
		}
		else
			x--;
		if(x<0)
		{
			if(ans==2*open)
				substrings++;
			else if(ans<2*open)
				substrings=1;
			ans=max(ans,2*open);
			open=0;
			x=0;
		}
	}
	if(x==0)
	{
		if(ans==2*open)
			substrings++;
		else if(ans<2*open)
			substrings=1;
		ans=max(ans,2*open);
	}
	if(ans==0)
		substrings=1;
	if(ans==sz(s))
		substrings=1;
	cout<<ans<<" "<<substrings<<endl;
	return 0;
}