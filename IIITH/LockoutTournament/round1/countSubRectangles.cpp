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

vector<ll> get_subarray_cnt(vector<ll>& a)
{
	ll i;
	ll n = sz(a);
	ll cnt = 0;
	vector<ll> dp(n+1, 0);
	for(i=0;i<sz(a);i++)
	{
		if(a[i] == 0)
		{
			for(ll j=cnt;j>=1;j--)
				dp[j] += 1 + cnt - j;
			cnt = 0;
		}
		else
			cnt++;
	}
	for(ll j=cnt;j>=1;j--)
		dp[j] += 1 + cnt - j;
	return dp;
}

void print_arr(vector<ll>& a)
{
	for(ll i=0;i<sz(a);i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll> a,b;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		b.pb(val);
	}
	vector<ll> div;
	for(i=1;i<=sqrt(k);i++)
	{
		if(k%i == 0)
		{
			div.pb(i);
			if(i == k/i)
				continue;
			div.pb(k/i);
		}
	}
	sort(all(div));
	vector<ll> dp1 = get_subarray_cnt(a);
	vector<ll> dp2 = get_subarray_cnt(b);
	ll ans = 0;
	for(i=0;i<sz(div);i++)
	{
		ll x = div[i];
		ll y = k/x;
		if(x > n || y > m)
			continue;
		ans += dp1[x]*dp2[y];
	}
	cout<<ans<<endl;
	return 0;
}
