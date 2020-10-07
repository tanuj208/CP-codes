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

ll m,n;
vector<pair<ll, pii>> edges;
vector<ll> parent(200005, -1);
vector<ll> d(200005, 1);

ll get_parent(ll v)
{
	if(parent[v] == -1)
		return v;
	parent[v] = get_parent(parent[v]);
	return parent[v];
}

ll connect(pair<ll,pii> edge)
{
	ll x1 = get_parent(edge.ss.ff);
	ll x2 = get_parent(edge.ss.ss);
	if(x1 == x2)
		return 0;
	if(d[x1] <= d[x2])
	{
		parent[x1] = x2;
		d[x2] += d[x1];
	}
	else
	{
		parent[x2] = x1;
		d[x1] += d[x2];
	}
	return edge.ff;
}

ll get_mst()
{
	sort(all(edges));
	ll i;
	ll min_sum = 0;
	for(i=0;i<sz(edges);i++)
		min_sum += connect(edges[i]);
	return min_sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>m>>n;
	vector<ll> a,b;
	ll i,j;
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		b.pb(val);
	}
	ll total_cost = 0;
	for(i=0;i<m;i++)
	{
		ll x;
		cin>>x;
		for(j=0;j<x;j++)
		{
			ll val;
			cin>>val;
			ll cost = a[i] + b[val-1];
			edges.pb(mp(-cost, mp(n+i+1, val)));
			total_cost += cost;
		}
	}
	ll mst_sum = get_mst();
	cout<<total_cost + mst_sum<<endl;
	return 0;
}
