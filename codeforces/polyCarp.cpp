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
	ll n=sz(s);
	ll i;
	ll ans=0;
	ll one=0;
	ll two=0;
	ll x=0;
	for(i=0;i<n;i++)
	{
		x+=(ll)(s[i]-'0');
		if(x%3==0)
		{
			x=0;
			ans++;
			one=0;
			two=0;
		}
		else if(x%3==1)
		{
			one++;
			if(one==2)
			{
				x=0;
				ans++;
				one=0;
				two=0;
			}
		}
		else if(x%3==2)
		{
			two++;
			if(two==2)
			{
				x=0;
				ans++;
				one=0;
				two=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}