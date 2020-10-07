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

vector<bool> is_prime(100006, true);

void seive()
{
	ll i;
	for(i=2;i<=100000;i++)
	{
		if(!is_prime[i])
			continue;
		for(ll j=2*i;j<=100000;j+=i)
			is_prime[j] = false;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	seive();
	while(t--)
	{
		ll i,n;
		cin>>n;
		vector<ll> primes;
		vector<ll> div;
		div.pb(n);
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i == 0)
			{
				div.pb(i);
				if(n/i != i)
					div.pb(n/i);
				if(is_prime[i])
					primes.pb(i);
				if(i != n/i && n/i <= 100000 && is_prime[n/i])
					primes.pb(n/i);
			}
		}
		ll tmp = n;
		for(i=0;i<sz(primes);i++)
		{
			while(tmp % primes[i] == 0)
				tmp /= primes[i];
		}
		if(tmp != 1)
			primes.pb(tmp);
		// for(i=0;i<sz(primes);i++)
		// 	cout<<primes[i]<<" ";
		// cout<<endl;
		// for(i=0;i<sz(div);i++)
		// 	cout<<div[i]<<" ";
		// cout<<endl;
		if(sz(primes) == 2 && sz(div) == 3)
		{
			for(i=0;i<sz(div);i++)
				cout<<div[i]<<" ";
			cout<<endl;
			cout<<1<<endl;
			continue;
		}
		if(sz(primes) == 1)
		{
			for(i=0;i<sz(div);i++)
				cout<<div[i]<<" ";
			cout<<endl<<0<<endl;
			continue;
		}
		sort(all(div));
		sort(all(primes));
		vector<bool> marked(sz(div) + 1, false);
		vector<ll> ans;
		ans.pb(n);
		marked[sz(div)-1] = true;
		for(i=0;i<sz(primes)-1;i++)
		{
			ll cur_p = primes[i];
			ll next_p = primes[i+1];
			ll j;
			for(j=0;j<sz(div);j++)
			{
				if(marked[j])
					continue;
				if(div[j] == cur_p * next_p)
				{
					marked[j] = true;
					continue;
				}
				if(div[j] % cur_p == 0)
				{
					marked[j] = true;
					ans.pb(div[j]);
				}
			}
			ans.pb(cur_p * next_p);
		}
		for(i=0;i<sz(div);i++)
		{
			if(!marked[i])
				ans.pb(div[i]);
		}
		for(i=0;i<sz(ans);i++)
			cout<<ans[i]<<" ";
		cout<<endl<<0<<endl;
	}
	return 0;
}
