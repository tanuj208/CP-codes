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

ll n;
vector<vector<ll>> ad(100005);
vector<ll> node_cnt(100005, 1);
ll a=-1,b=-1;

void reset()
{
	a=-1;
	b=-1;
	ll i;
	for(i=0;i<=n;i++)
	{
		ad[i].clear();
		node_cnt[i] = 1;
	}
}

void dfs(ll v, ll par)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x = ad[v][i];
		if(x == par)
			continue;
		dfs(x, v);
		// cout<<x<<" F"<<node_cnt[x]<<endl;
		// cout<<n<<endl;
		if(node_cnt[x] == n/2)
		{
			a = v;
			b = x;
			// cout<<a<<"F"<<b<<endl;
		}
		node_cnt[v] += node_cnt[x];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		reset();
		ll i;
		ll u,v;
		for(i=0;i<n-1;i++)
		{
			cin>>u>>v;
			ad[u].pb(v);
			ad[v].pb(u);
		}
		if(n%2==1)
		{
			cout<<u<<" "<<v<<endl<<u<<" "<<v<<endl;
			continue;
		}
		dfs(1, 0);
		if(a==-1)
		{
			cout<<u<<" "<<v<<endl<<u<<" "<<v<<endl;
			continue;
		}
		ll c;
		for(i=0;i<sz(ad[b]);i++)
			if(ad[b][i] != a)
				c=ad[b][i];
		cout<<b<<" "<<c<<endl;
		cout<<a<<" "<<c<<endl;
	}
	return 0;
}
