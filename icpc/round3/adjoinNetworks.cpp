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
vector<ll> ad[100005];
vector<ll> vis(100005, 0);
vector<ll> diams;

ll diameter = 0;
ll dfs(ll v, ll p)
{
	ll i;
	vis[v]=1;
	ll mx=0;
	ll smx=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		ll val=dfs(x, v);
		if(val>mx)
			smx=mx, mx=val;
		else if(val>smx)
			smx=val;
	}
	if(mx==0)
		return 1;
	diameter = max(diameter, mx+smx);
	return 1+mx;
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
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			ll tmp = dfs(i, -1);
			diams.pb(diameter);
			diameter = 0;
		}
	}
	sort(all(diams));
	reverse(all(diams));
	if(sz(diams)==1)
	{
		cout<<diams[0]<<endl;
		return 0;
	}
	ll ans=diams[0];
	ll x=diams[1];
	double xx = (double)x / 2.0;
	double xx2 = (double)ans / 2.0;
	// cout<<xx<<" "<<xx2<<endl;
	ans=max(ans, (ll)max(x, (ll)(ceil(xx) + ceil(xx2) + 1)));
	// for(i=0;i<sz(diams);i++)
	// 	cout<<diams[i]<<" ";
	// cout<<endl;
	// cout<<ans<<endl;
	for(i=2;i<sz(diams);i++)
	{
		x=diams[i];
		xx = (double)x / 2.0;
		xx2 = (double)ans / 2.0;
		// cout<<xx<<" "<<xx2<<endl;
		ans=max(ans, (ll)max(x, (ll)(ceil(xx) + ceil(xx2) + 1)));
	}
	cout<<ans<<endl;
	return 0;
}