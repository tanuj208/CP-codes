#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

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
	ll t,i;
	cin>>t;

	ll pp[100005];
	pp[0]=1;
	for(i=1;i<=100000;i++)
		pp[i]=(pp[i-1]*2)%mod;

	ll fac[100005];
	fac[0]=1;
	for(i=1;i<=100000;i++)
		fac[i]=(fac[i-1]*i)%mod;

	while(t--)
	{
		ll n;
		cin>>n;
		map<ll,ll> x;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			x[val]++;
		}
		auto it=x.end();
		it--;
		ll flag=0;
		ll ans=1;
		for(;it!=x.begin();it--)
		{
			ll val=it->second;
			if(flag==1)
			{
				ans=(ans*val)%mod;
				val--;
			}
			if(val==0)
			{
				flag=0;
				continue;
			}
			if(val%2==0)
			{
				flag=0;
				ans = (ans*divisionMod(fac[val],(pp[val/2]*fac[val/2])%mod))%mod;
			}
			else
			{
				ans=(ans*val)%mod;
				flag=1;
				val--;
				ans = (ans*divisionMod(fac[val],(pp[val/2]*fac[val/2])%mod))%mod;
			}
		}
		ll val=x.begin()->second;
		// cout<<flag<<endl;
		if(flag==1)
		{
			ans=(ans*val)%mod;
			val--;
		}
		if(val!=0)
		{
			flag=0;
			ans = (ans*divisionMod(fac[val],(pp[val/2]*fac[val/2])%mod))%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}