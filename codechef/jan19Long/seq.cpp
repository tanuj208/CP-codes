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

bool check(vector<ll> ans)
{
	ll i;
	ll n=sz(ans);
	for(i=0;i<sz(ans);i++)
		if(__gcd(ans[i], ans[(i+1)%n])==1 || __gcd(ans[(i+2)%n], __gcd(ans[i], ans[(i+1)%n])) != 1)
			return -1;
	return 1;
}

vector<ll> primes;
ll prime[100005]={true};
map<ll,bool> x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,j;
	for(i=0;i<=100000;i++)
		prime[i]=true;
	for(i=2;i<=100000;i++)
	{
		if(!prime[i])
			continue;
		for(j=2*i;j<=100000;j+=i)
			prime[j]=false;
	}
	// ll cnt=0;
	primes.pb(2);
	for(i=3;i<=100000;i++)
	{
		if(prime[i])
		{
			if(i*primes[sz(primes)-1] > 1e9)
				break;
			primes.pb(i);
		}
	}
	ll N=sz(primes);
	// cout<<sz(primes)<<endl;
	ll t;
	cin>>t;
	vector<ll> ans;
	while(t--)
	{
		x.clear();
		ans.clear();
		ll n;
		cin>>n;
		ll cntr=1;
		i=0;
		while(true)
		{
			if(cntr==N)
				break;
			ll y=(i+cntr)%N;
			ll xx=primes[i]*primes[y];
			if(x.find(xx)!=x.end())
			{
				i=y;
				if(i==0)
					cntr++;
				continue;
			}
			if(sz(ans)==n-1 && i!=0)
			{
				for(ll zz=N-1;zz>=0;zz--)
				{
					xx=primes[i]*primes[zz];
					if(x.find(xx)==x.end() && zz!=i)
					{
						ans[0]*=primes[zz];
						break;
					}
				}
			}
			else if(sz(ans)==n-1 && i==0)
			{
				for(ll zz=N-1;zz>0;zz--)
				{
					xx=primes[i]*primes[zz];
					ll tmp=primes[1]*primes[zz];
					if(x.find(xx)==x.end() && x.find(tmp)==x.end())
					{
						ans[0]=tmp;
						break;
					}
				}
			}
			ans.pb(xx);
			if(sz(ans)==n)
				break;
			x[xx]=true;
			i=y;
			if(i==0)
				cntr++;
		}
		if(sz(ans)!=n)
		{
			cout<<-1<<endl;
			continue;
		}
		for(i=0;i<sz(ans);i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}