#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll p[200005];
ll n;

pii hashing(string s)
{
	ll fhash,rhash;
	ll i;
	fhash=s[0]-'a'+1;
	for(i=1;i<n;i++)
	{
		ll x=s[i]-'a'+1;
		fhash=(fhash+p[i]*x)%mod;
	}
	rhash=s[n-1]-'a'+1;
	for(i=n-2;i>=0;i--)
	{
		ll x=s[i]-'a'+1;
		rhash=(rhash+p[n-1-i]*x)%mod;
	}
	return mp(fhash,rhash);
}

ll divisionMod(ll a, ll b)
{
	ll val=1;
	ll power=mod-2;
	while(power!=0)
	{
		if(power%2==1)
		{
			val=(val*b)%mod;
		}
		b=b*b;
		b=b%mod;
		power=power/2;
	}
	return (a*val)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll i;
	p[0]=1;
	for(i=1;i<=200000;i++)
		p[i]=(37*p[i-1])%mod;
	while(t--)
	{
		string s;
		cin>>s;
		ll ans=0;
		n=sz(s);
		pii xxxx=hashing(s);
		ll fhash=xxxx.first;
		ll rhash=xxxx.second;
		for(i=0;i<n-1;i++)
		{
			ll x=s[n-1-i]-'a'+1;
			if(fhash==rhash)
				ans++;
			fhash=(fhash-((p[n-1]*x)%mod)+mod)%mod;
			fhash=(fhash*37)%mod;
			fhash=(fhash+x)%mod;

			rhash=(rhash-x+mod)%mod;
			rhash=divisionMod(rhash,37);
			rhash=(rhash+(p[n-1]*x)%mod)%mod;
		}
		if(fhash==rhash)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}