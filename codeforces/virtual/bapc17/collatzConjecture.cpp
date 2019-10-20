#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	set<ll> ans;
	vector<pii> dp(500005);
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	dp[0]=mp(a[0],-1);
	ans.insert(a[0]);
	for(i=1;i<n;i++)
	{
		// cout<<i<<endl;
		ll j=i-1;
		ll lastj=i;
		dp[i]=mp(a[i], -1);
		ans.insert(a[i]);
		while(j>=0)
		{
			ll nxtj=dp[j].second;
			dp[j]=mp(__gcd(dp[j].first, a[i]), -1);
			ans.insert(dp[j].first);
			if(dp[j].first!=dp[lastj].first)
			{
				dp[lastj].second=j;
				lastj=j;
			}
			j=nxtj;
		}
	}
	cout<<sz(ans)<<endl;
	return 0;
}