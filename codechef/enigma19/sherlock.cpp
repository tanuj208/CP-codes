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

vector<ll> a;
vector<ll> ad[1005];
ll dp[1005][1025];
ll ans=0;

ll dfs(ll v,ll p,ll level, ll curXor)
{
	ll i;
	ll ans=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		ans+=dfs(x, v, max(level-1,(ll)0), curXor);
	}
	if(level!=0)
		return ans;
	if(dp[v][curXor]!=-1)
		return dp[v][curXor];
	ll ans2=a[v];
	ll xoor=curXor^a[v];
	if(xoor>1024)
	{
		dp[v][curXor]=max(ans,ans2);
		return dp[v][curXor];
	}
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		ans2+=dfs(x,v,xoor,xoor);
	}
	dp[v][curXor]=max(ans,ans2);
	return dp[v][curXor];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i,j;
	a.pb(-1);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<=1000;i++)
		for(j=0;j<=1024;j++)
			dp[i][j]=-1;
	for(i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	cout<<dfs(1,-1,0,0)<<endl;
	return 0;
}