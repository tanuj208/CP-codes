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

vector<pii> fac[500005];
vector<bool> p(500005, true);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> primes;
	ll i,j;
	for(i=2;i<=n;i++)
	{
		if(!p[i])
			continue;
		primes.pb(i);
		for(j=2*i;j<=n;j+=i)
		{
			ll tmp=j;
			ll cnt=0;
			while(tmp%i==0)
			{
				tmp/=i;
				cnt++;
			}
			fac[j].pb(mp(i, cnt));
			p[j]=false;
		}
	}
	ll cnt=n-1;
	for(i=0;i<sz(primes);i++)
	{
		cout<<1<<" ";
		cnt--;
		if(cnt==0)
			break;
	}
	ll cur=1;
	while(cnt != 0)
	{
		cur++;
		ll tmp = cur;
		if(sz(fac[tmp]) == 0)
		{
			for(i=0;i<sz(primes);i++)
			{
				if(primes[i] > tmp)
					break;
				if(primes[i] * tmp > n)
					break;
				cout<<tmp<<" ";
				cnt--;
				if(cnt==0)
					break;
			}
		}
		else
		{
			for(i=0;i<sz(primes);i++)
			{
				if(primes[i] > fac[tmp][0].ff)
					break;
				if(primes[i] * tmp > n)
					break;
				cout<<tmp<<" ";
				cnt--;
				if(cnt==0)
					break;
			}
			for(i=0;i<sz(fac[tmp]);i++)
			{
				ll pp=fac[tmp][i].ff;
				ll cnt=fac[tmp][i].ss;
				if(pp*tmp > n)
					break;
				if(power(pp, cnt+1) > tmp)
					continue;
				cout<<tmp<<" ";
				cnt--;
				if(cnt==0)
					break;
			}
		}
	}
	cout<<endl;
	return 0;
}