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

ll n,m;
vector<pii> ad[500005];
vector<ll> dp(500005, -1);

ll dfs(ll v, vector<ll>& vis, vector<ll>& ans)
{
	if(dp[v] != -1)
		return dp[v];
	if(vis[v] == 1)
		return LLONG_MAX;
	vis[v]=1;
	ll i;
	ll min_zero = LLONG_MAX;
	ll min_one = LLONG_MAX;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].ff;
		ll col = ad[v][i].ss;
		ll dist = dfs(x, vis, ans);
		if(col == 0)
			min_zero = min(min_zero, dist);
		else
			min_one = min(min_one, dist);
	}
	if(min_zero > min_one)
		ans[v] = 0;
	else
		ans[v] = 1;
	dp[v] = max(min_zero, min_one);
	if(dp[v] != LLONG_MAX)
		dp[v]++;
	vis[v]=0;
	return dp[v];
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
		ll u,v,w;
		cin>>u>>v>>w;
		ad[u].pb(mp(v, w));
	}
	vector<ll> vis(n+1, 0);
	vector<ll> ans(n+1, 0);
	dp[n] = 0;
	dfs(1, vis, ans);
	if(dp[1] == LLONG_MAX)
		cout<<-1<<endl;
	else
		cout<<dp[1]<<endl;
	for(i=1;i<=n;i++)
		cout<<ans[i];
	cout<<endl;

	// for(i=1;i<=n;i++)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
	return 0;
}
