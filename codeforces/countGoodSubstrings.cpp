#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll even=0,odd=0;
ll e=0,o=0;

void compute(ll len)
{
	if(len%2==0)
	{
		even+=(e+1);
		odd+=o;
		o++;
	}
	else
	{
		odd+=(e+1);
		even+=o;
		e++;
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll n=sz(s);
	ll i;
	ll ind=-1;
	odd=n;
	for(i=1;i<n;i++)
	{
		if(s[i]==s[0])
		{
			ll len=i+1;
			compute(len);
		}
		else if(s[i]!=s[0] && ind==-1)
			ind=i;
	}
	e=0,o=0;
	if(ind==-1)
	{
		cout<<even<<" "<<odd<<endl;
		return 0;
	}
	for(i=ind+1;i<n;i++)
	{
		if(s[i]==s[ind])
		{
			ll len=i-ind+1;
			compute(len);
		}
	}
	cout<<even<<" "<<odd<<endl;
	return 0;
}