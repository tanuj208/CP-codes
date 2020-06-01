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

ll rec(ll c, ll rec_len, vector<ll>& primes, ll idx, ll cur_val)
{
	if(rec_len==0)
		return c/cur_val;
	ll ret_val=0;
	ll i;
	for(i=idx;i<sz(primes);i++)
	{
		if(sz(primes)-i-1 < rec_len-1)
			break;
		ret_val+= rec(c, rec_len-1, primes, i+1, cur_val*primes[i]);
	}
	return ret_val;
}

ll g(ll c, vector<ll>& primes)
{
	ll i;
	ll ans=0;
	for(i=1;i<=sz(primes);i++)
	{
		if(i%2==1)
			ans+=rec(c, i, primes, 0, 1);
		else
			ans-=rec(c, i, primes, 0, 1);
		// cout<<ans<<endl;
	}
	return ans;
}

ll f(ll c, vector<ll>&  primes)
{
	return c-g(c, primes);
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
		ll a,m;
		cin>>a>>m;
		ll x=__gcd(a,m);
		a/=x;
		m/=x;
		vector<ll> primes;
		ll i,j;
		ll tmp=m;
		for(i=2;i<=100000;i++)
		{
			if(tmp%i==0)
				primes.pb(i);
			while(tmp%i == 0)
				tmp/=i;
		}
		if(tmp!=1)
			primes.pb(tmp);
		cout<<f(a+m-1, primes)-f(a-1, primes)<<endl;
	}
	return 0;
}