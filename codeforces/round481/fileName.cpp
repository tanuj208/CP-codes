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
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll i;
	ll x=0;
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='x')
		{
			x++;
		}
		else
		{
			if(x>=3)
				ans+=(x-2);
			x=0;
		}
	}
	if(x>2)
		ans+=(x-2);
	cout<<ans<<endl;
	return 0;
}