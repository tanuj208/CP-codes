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

vector<vector<ll>> dp(10005, vector<ll> (1005, -1)); // -1 uninitialized, -2 init, -3 not possible
ll n,m;
vector<ll> d;
ll g,r;

ll rec(ll i, ll t)
{
	if(dp[i][t] == -2)
		dp[i][t] = -3;
	if(dp[i][t] != -1)
		return dp[i][t];
	dp[i][t] = -2;
	if(t == g)
	{
		ll x = rec(i, 0);
		if(i==3 && t == 11)
			cout<<x<<endl;
		if(x >= 0)
			dp[i][t] = r + x;
		else
			dp[i][t] = -3;
		return dp[i][t];
	}
	if(i!=0)
	{
		ll diff = d[i] - d[i-1];
		if(diff + t <= g)
		{
			ll x = rec(i-1, diff+t);
			if(x >= 0)
				dp[i][t] = diff + x;
		}
	}
	if(i!=m-1)
	{
		ll diff = d[i+1] - d[i];
		if(diff + t <= g)
		{
			ll x = rec(i+1, diff+t);
			if(x >= 0)
			{
				if(dp[i][t] < 0)
					dp[i][t] = diff + x;
				else
					dp[i][t] = min(dp[i][t], diff + x);
			}
		}
	}
	if(dp[i][t] < 0)
		dp[i][t] = -3;
	return dp[i][t];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		d.pb(val);
	}
	sort(all(d));
	cin>>g>>r;
	dp[0][g] = 0;
	ll ans=LLONG_MAX;
	cout<<rec(3,0)<<endl;
	cout<<rec(3,11)<<endl;
	for(i=0;i<=g;i++)
	{
		ll x= rec(m-1, i);
		if(x>=0)
			ans = min(ans, x);
	}
	if(ans == LLONG_MAX)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}