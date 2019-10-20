#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll powerr(ll a, ll b)
{
	ll val=1;
	ll power=b;
	while(power!=0)
	{
		if(power%2==1)
			val=(val*a)%mod;
		a=a*a;
		a=a%mod;
		power=power/2;
	}
	return val%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll a=powerr(2,n-1);
	ll num=a-n;
	ll den=a;
	ll x=__gcd(num,den);
	num/=x;
	den/=x;
	ll ans=(num*(powerr(den,mod-2)))%mod;
	cout<<ans<<endl;
	return 0;
}