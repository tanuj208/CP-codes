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

vector<ll> ad[100005];

vector<ll> vis(100005, 0);

bool dfs(ll v, ll label)
{
	if(vis[v]!=0)
		return false;
	vis[v]=label;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		bool tmp = dfs(x,label);
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ll> c;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		c.pb(val);
	}
	for(i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		ad[x].pb(y);
		ad[y].pb(x);
	}
	ll label=1;
	for(i=1;i<=n;i++)
	{
		if(dfs(i, label))
			label++;
	}
	vector<ll> cost(label, INT_MAX);
	for(i=1;i<=n;i++)
		cost[vis[i]] = min(cost[vis[i]], c[i-1]);
	ll ans=0;
	for(i=1;i<label;i++)
	{
		if(cost[i]!=INT_MAX)
			ans+=cost[i];
	}
	cout<<ans<<endl;

	return 0;
}