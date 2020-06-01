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

ll mod=998244353;

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
	ll n,m,l,r;
	cin>>n>>m>>l>>r;
	ll xx = (r-l+1);
	ll evens=xx/2, odds=xx/2;
	if(xx%2==1)
	{
		if(r%2==1)
			odds++;
		else
			evens++;
	}

	if((n*m) % 2==1)
	{
		ll x=n*m%mod;
		ll y=(evens+odds)%mod;
		cout<<power(y,x)<<endl;
	}
	else
	{
		ll x = (n*m)%mod;
		ll tmp = (evens+odds)%mod;
		ll x1 = power(tmp,x);
		tmp = (evens-odds+2*mod)%mod;
		ll x2 = power(tmp,x);
		ll ans=(x1+x2)%mod;
		ans = (ans * power(2, mod-2))%mod;
		cout<<ans<<endl;
	}
	return 0;
}