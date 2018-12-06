#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool isPrime(ll x)
{
	ll i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	vector<ll> primes;
	vector<ll> sPrimes;
	ll i,j;
	for(i=2;i<=200;i++)
		if(isPrime(i))
			primes.pb(i);
	for(i=0;i<sz(primes);i++)
		for(j=i+1;j<sz(primes);j++)
			sPrimes.pb(primes[i]*primes[j]);
	set<ll> ans;
	for(i=0;i<sz(sPrimes);i++)
		for(j=0;j<sz(sPrimes);j++)
			ans.insert(sPrimes[i]+sPrimes[j]);
	while(t--)
	{
		ll n;
		cin>>n;
		if(ans.find(n)!=ans.end())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}