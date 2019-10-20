#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<bool> isPrime(100005,true);
vector<ll> primes;

void precalc()
{
	ll i,j;
	isPrime[1]=false;
	for(i=2;i<=100000;i++)
	{
		if(!isPrime[i])
			continue;
		for(j=2*i;j<=100000;j+=i)
			isPrime[j]=false;
	}
	for(i=2;i<=100000;i++)
		if(isPrime[i])
			primes.pb(i);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	if(m<n-1)
	{
		cout<<"Impossible\n";
		return 0;
	}
	precalc();
	vector<pii> ans;
	ll i,j;
	for(i=2;i<=n;i++)
		ans.pb(mp(1,i));
	m-=(n-1);
	for(i=0;i<sz(primes);i++)
	{
		if(m==0)
			break;
		ll x=primes[i];
		if(x>n)
			break;
		for(j=2;j<=n;j++)
		{
			if(m==0)
				break;
			if(j==x || (j<x && isPrime[j]) || __gcd(j,x)!=1)
				continue;
			ans.pb(mp(x,j));
			m--;
		}
	}
	for(i=4;i<=n;i++)
	{
		if(m==0)
			break;
		if(isPrime[i])
			continue;
		for(j=i+1;j<=n;j++)
		{
			if(isPrime[j])
				continue;
			if(m==0)
				break;
			if(__gcd(i,j)==1)
			{
				ans.pb(mp(i,j));
				m--;
			}
		}
	}
	if(m!=0)
	{
		cout<<"Impossible\n";
		return 0;
	}
	cout<<"Possible\n";
	for(i=0;i<sz(ans);i++)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}