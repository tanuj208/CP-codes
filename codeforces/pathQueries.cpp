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

ll ans = 0;

vector<ll> p(200005, -1);
vector<ll> d(200005, 1);

ll par(ll v)
{
	if(p[v] == -1)
		return v;
	p[v] = par(p[v]);
	return p[v];
}

void connect(ll v1, ll v2)
{
	ll x1 = par(v1);
	ll x2 = par(v2);
	ans += d[x1] * d[x2];
	if(d[x1] <= d[x2])
	{
		p[x1] = x2;
		d[x2] += d[x1];
	}
	else
	{
		p[x2] = x1;
		d[x1] += d[x2];
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	vector<pair<ll,pii>> ed;
	for(i=1;i<n;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		ed.pb(mp(w, mp(u, v)));
	}
	sort(all(ed));
	vector<pii> q;
	for(i=0;i<m;i++)
	{
		ll qi;
		cin>>qi;
		q.pb(mp(qi, i));
	}
	sort(all(q));
	ll idx=0;
	vector<ll> an(m);
	for(i=0;i<m;i++)
	{
		while(idx < sz(ed) && ed[idx].ff <= q[i].ff)
		{
			connect(ed[idx].ss.ff, ed[idx].ss.ss);
			idx++;
		}
		an[q[i].ss] = ans;
	}
	for(i=0;i<m;i++)
		cout<<an[i]<<" ";
	cout<<endl;
	return 0;
}