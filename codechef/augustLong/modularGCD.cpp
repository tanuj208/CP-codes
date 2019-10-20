#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll power(ll a, ll b)
{
	ll val=1;
	ll power=b;
	while(power!=0)
	{
		if(power%2==1)
			val=(val*a)%mod;
		a=(a*a)%mod;
		power/=2;
	}
	return val%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,n;
		cin>>a>>b>>n;
		ll x=abs(a-b);
		vector<ll> fac;
		ll i;
		for(i=1;i<=sqrt(x);i++)
			if(x%i==0)
				fac.pb(i),fac.pb(x/i);
		sort(fac.begin(),fac.end());
		ll ans=1;
		for(i=0;i<sz(fac);i++)
		{
			ll aa=(power(a,n)*power(fac[i],mod-2))%mod;
			ll bb=(power(b,n)*power(fac[i],mod-2))%mod;
			if((aa+bb)%mod==1)
				ans=max(ans,fac[i]);
		}
		cout<<ans<<endl;
	}
	cout<<((mod+1)*power(2,mod-2))%mod<<endl;
	return 0;
}