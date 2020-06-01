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

vector<bool> p(100005, true);
vector<ll> primes;

void sieve()
{
	ll i,j;
	for(i=2;i<=100000;i++)
	{
		if(!p[i])
			continue;
		for(j=2*i;j<=100000;j+=i)
			p[j]=false;
	}
	for(i=2;i<=100000;i++)
		if(p[i])
			primes.pb(i);
	return;
}

bool perfect_2_power(ll x)
{
	while(x!=1)
	{
		if(x%2!=0)
			return false;
		x/=2;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	sieve();
	ll i;
	ll prs = 0;
	ll oth = 0;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		if(val == 1)
			continue;
		if(perfect_2_power(val) || binary_search(all(primes), val))
			prs++;
		else
		{
			ll j;
			bool div = false;
			for(j=0;j<sz(primes);j++)
			{
				if(val % primes[j] == 0)
				{
					div = true;
					break;
				}
			}
			if(div)
				oth++;
			else
				prs++;
		}
	}
	string bob = "Bob";
	string alice = "Alice";
	if(oth == 1)
		cout<<alice<<endl;
	else if((oth+prs)%2==0)
		cout<<bob<<endl;
	else if((oth+prs)%2==1)
		cout<<alice<<endl;
	return 0;
}