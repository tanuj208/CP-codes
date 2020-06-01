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

// priority_queue <ll,vector<ll>,greater<ll> > parent;

typedef long long ll;
typedef pair<ll,ll> pii;

vector<ll> ad[200005];
vector<ll> p(200005, 0);
vector<ll> l(200005, 0);
ll n,m;

void dfs(ll v)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(p[v]==x)
			continue;
		p[x]=v;
		l[x]=l[v]+1;
		dfs(x);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	for(i=0;i<n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	dfs(1);
	for(i=0;i<m;i++)
	{
		ll k;
		cin>>k;
		vector<ll> v;
		ll x = 1;
		ll mxlvl = 0;
		ll j;
		for(j=0;j<k;j++)
		{
			ll val;
			cin>>val;
			if(val!=1)
			{
				v.pb(p[val]);
				if(l[p[val]] > mxlvl)
				{
					mxlvl = l[p[val]];
					x = p[val];
				}
			}
		}
		vector<ll> tmp;
		while(x!=1)
		{
			tmp.pb(x);
			x = p[x];
		}
		tmp.pb(1);
		sort(all(tmp));
		bool pos = true;
		for(j=0;j<sz(v);j++)
		{
			if(binary_search(all(tmp), v[j]))
				continue;
			else
			{
				pos = false;
				break;
			}
		}
		if(pos)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}