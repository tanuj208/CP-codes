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
	ll q;
	cin>>q;
	ll fac[1005];
	fac[0]=1;
	ll i;
	for(i=1;i<=1000;i++)
		fac[i]=(i*fac[i-1])%mod;
	while(q--)
	{
		ll n,t;
		cin>>n>>t;
		ll ans=1;
		ll flag=0;
		for(i=n+1;i<=n+t+1;i++)
		{
			if(flag==0 && i%(t+1)==0)
			{
				ll x=i/(t+1);
				x=x%mod;
				ans=(ans*x)%mod;
				flag=1;
			}
			else
			{
				ll x=i%mod;
				ans=(ans*x)%mod;
			}
		}
		ans=(ans-fac[t]+mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}