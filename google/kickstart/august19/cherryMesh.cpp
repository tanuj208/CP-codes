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

void dfs(ll v, vector<ll>& vis, unordered_map<ll,bool>& hsh)
{
	if(vis[v]==1)
		return;
	hsh[v]=true;
	vis[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
		dfs(ad[v][i], vis, hsh);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll z;
	for(z=1;z<=t;z++)
	{
		ll n,m;
		cin>>n>>m;
		ll i;
		for(i=0;i<=n+2;i++)
			ad[i].clear();
		for(i=0;i<m;i++)
		{
			ll c,d;
			cin>>c>>d;
			ad[c].pb(d);
			ad[d].pb(c);
		}
		vector<ll> vis(n+5, 0);
		unordered_map<ll,bool> hsh;
		ll ans=0;
		for(i=1;i<=n;i++)
		{
			dfs(i, vis, hsh);
			ll x=sz(hsh);
			hsh.clear();
			// cout<<i<<" "<<x<<endl;
			if(x>=1)
			{
				ans+=2;
				ans+=(x-1);
			}
		}
		cout<<"Case #"<<z<<": "<<ans-2<<endl;
	}
	return 0;
}