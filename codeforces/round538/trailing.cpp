#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

vector<ll> primes;
vector<bool> prime(1000005);
map<ll,ll> fac;

void pre(ll n)
{
	ll i,j;
	for(i=2;i<=1000000;i++)
		prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	for(i=2;i<=1000000;i++)
		for(j=2*i;j<=100000;j+=i)
			prime[j]=false;
	for(i=2;i<=1000000;i++)
		if(prime[i])
			primes.pb(i);
	for(i=0;i<sz(primes);i++)
	{
		ll x= primes[i];
		while(n%x==0)
		{
			fac[x]++;
			n/=x;
		}
	}
	if(n!=1)
		fac[n]++;
}

ll kitnibar(ll n,ll x)
{
	ll ans=0;
	ll tmp=x;
	while(true)
	{
		ll xx=n/x;
		if(xx==0)
			break;
		ans+=xx;
		if(x>1e18/tmp)
			break;
		x*=tmp;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,b,i;
	cin>>n>>b;
	pre(b);
	ll ans = LLONG_MAX;
	// cout<<kitnibar(1000000000000000000, 1000000009)<<endl;
	for(auto it=fac.begin();it!=fac.end();it++)
	{
		ll pri = it->first;
		ll cnt = it->second;
		ans=min(ans,(kitnibar(n,pri)/cnt));
	}
	cout<<ans<<endl;
	return 0;
}