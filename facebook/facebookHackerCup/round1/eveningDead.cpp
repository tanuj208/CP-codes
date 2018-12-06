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
	ll t;
	cin>>t;
	ll q;
	for(q=1;q<=t;q++)
	{
		ll n,m;
		cin>>n>>m;
		vector<pii> y;
		ll i;
		for(i=1;i<n;i++)
		{
			ll a,b;
			cin>>a>>b;
			y.pb(mp(a,b));
		}
		vector<ll> prob(2005,1);   // prob that ith yard will be safe
		for(i=0;i<m;i++)
		{
			ll yy,h;
			cin>>yy>>h;
			vector<ll> tmp(2005,1);
			tmp[yy]=0;
			ll j;
			for(j=yy+1;j<=n;j++)
			{
				ll a=y[j-2].first;
				ll b=y[j-2].second;
				if(h<a)
					break;
				else if(h>b)
					tmp[j]=tmp[j-1];
				else
					tmp[j]=(((1-tmp[j-1]+mod)%mod*divisionMod(b-h,b-a+1))%mod+tmp[j-1])%mod;
			}
			for(j=yy-1;j>=1;j--)
			{
				ll a=y[j-1].first;
				ll b=y[j-1].second;
				if(h<a)
					break;
				else if(h>b)
					tmp[j]=tmp[j+1];
				else
					tmp[j]=(((1-tmp[j+1]+mod)%mod*divisionMod(b-h,b-a+1))%mod+tmp[j+1])%mod;
			}
			for(j=1;j<=n;j++)
				prob[j]=(prob[j]*tmp[j])%mod;
		}
		ll ans=1;
		for(i=1;i<=n;i++)
			ans=(ans*(1-prob[i]+mod)%mod)%mod;
		ans=(1-ans+mod)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}