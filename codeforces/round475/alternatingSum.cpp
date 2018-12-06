#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000009;

ll power(ll x,ll y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return (x*((temp*temp)%mod))%mod;
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
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	ll x[100006];
	ll i;
	for(i=0;i<k;i++)
	{
		char c;
		cin>>c;
		if(c=='+')
			x[i]=1;
		else
			x[i]=-1;
	}
	ll ans=0;
	for(i=0;i<k;i++)
	{
		ll temp=(power(a,n-i)*power(b,i))%mod;
		ans=(ans+(x[i]*temp+2*mod)%mod+mod)%mod;
	}
	ll tempans;
	ll m=divisionMod(power(b,k),power(a,k));
	if(m!=1)
	{
		ll tempa=(power(m,(n+1)/k)-1+2*mod)%mod;
		ll tempb=(m-1+2*mod)%mod;
		tempans=divisionMod(tempa,tempb);
	}
	else
		tempans=(n+1)/k;
	ans=(ans*tempans)%mod;
	cout<<ans<<endl;
	return 0;
}