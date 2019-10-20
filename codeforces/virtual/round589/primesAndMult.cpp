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

// priority_queue <ll,vector<ll>,greater<ll> > p;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll x,n;
	cin>>x>>n;
	vector<ll> primes;
	vector<bool> pr(1e5+5, true);
	pr[1]=false;
	ll i,j;
	for(i=2;i<=100000;i++)
	{
		if(!pr[i])
			continue;
		if(x%i==0)
			primes.pb(i);
		while(x!=0 && x%i==0)
			x/=i;
		for(j=2*i;j<=100000;j+=i)
			pr[j]=false;
	}
	if(x!=1)
		primes.pb(x);
	ll ans=1;
	for(i=0;i<sz(primes);i++)
	{
		ll cnt=0;
		ll cur = primes[i];
		while(true)
		{
			cnt+=n/cur;
			if(cur>n/primes[i])
				break;
			cur*=primes[i];
			if(n/cur==0)
				break;
		}
		ans=(ans*power(primes[i], cnt))%mod;
	}
	cout<<ans<<endl;
	return 0;
}