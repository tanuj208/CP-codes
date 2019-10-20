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
	ll n,k;
	cin>>n>>k;
	vector<ll> dp(n+5, 0);
	dp[0]=1;
	dp[1]=1;
	ll i;
	for(i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		ll x = power(k, 2*(i-1));
		ll y=(power(k, (i-1)) - power(k-1, (i-1)) + mod)%mod;
		y = (y*y)%mod;
		y = ((k-1)*y)%mod;
		x = (x+y)%mod;
		dp[i] = (dp[i]*x)%mod;
		x = dp[i-2];
		x = (x*(i-1))%mod;
		x = (x*(i-1))%mod;
		x = (x*power(k, 2*i-3))%mod;
		x = (x*power(k-1, 2*i-3))%mod;
		dp[i] =(dp[i]+x)%mod;
	}
	cout<<dp[n]<<endl;
	return 0;
}