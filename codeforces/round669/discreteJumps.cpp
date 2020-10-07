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

void func(vector<ll>& h, vector<vector<ll>>& jumps, bool flag)
{
	vector<pii> arr;
	arr.pb(mp(h[0], 0));
	ll i;
	for(i=1;i<sz(h);i++)
	{
		if((h[i] >= arr[0].ff && flag) || (h[i] <= arr[0].ff && !flag))
		{
			for(ll j=0;j<sz(arr);j++)
				jumps[arr[j].ss].pb(i);
			arr.clear();
			arr.pb(mp(h[i], i));
			continue;
		}
		ll idd;
		if(flag)
			idd = lower_bound(all(arr), mp(h[i], i), greater<pii>()) - arr.begin();
		else
			idd = lower_bound(all(arr), mp(h[i], (ll)0)) - arr.begin();
		// cout<<idd<<" "<<sz(arr)<<endl;
		if(idd == sz(arr))
		{
			arr.pb(mp(h[i], i));
			continue;
		}
		ll start = idd-1;
		if(arr[idd].ff == h[i])
			start++;
		for(ll j=start;j<sz(arr);j++)
			jumps[arr[j].ss].pb(i);
		while(sz(arr) != idd)
			arr.pop_back();
		arr.pb(mp(h[i], i));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> h;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		h.pb(val);
	}
	vector<vector<ll>> jumps(n+1);
	func(h, jumps, true);
	func(h, jumps, false);
	// for(i=0;i<n;i++)
	// {
	// 	cout<<i<<" ";
	// 	for(ll j=0;j<sz(jumps[i]);j++)
	// 		cout<<jumps[i][j]<<" ";
	// 	cout<<endl;
	// }
	vector<ll> dp(n+1, LLONG_MAX);
	dp[0] = 0;
	for(i=0;i<n-1;i++)
	{
		ll j;
		for(j=0;j<sz(jumps[i]);j++)
		{
			ll dest = jumps[i][j];
			dp[dest] = min(dp[dest], dp[i] + 1);
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
