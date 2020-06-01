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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<ll> div[200005];
	for(ll i=1;i<=200000;i++)
		for(ll j=i;j<=200000;j+=i)
			div[j].pb(i);

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> p,c;
		ll i;
		p.pb(0);
		c.pb(0);
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			p.pb(val);
		}
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			c.pb(val);
		}
		vector<vector<ll>> clusters;
		vector<ll> vis(n+2, 0);
		for(i=1;i<=n;i++)
		{
			if(vis[i]==1)
				continue;
			vector<ll> cur;
			ll x=i;
			while(vis[x]==0)
			{
				vis[x]=1;
				cur.pb(x);
				x = p[x];
			}
			clusters.pb(cur);
		}
		ll j;
		ll ans=INT_MAX;
		for(i=0;i<sz(clusters);i++)
		{
			ll x=sz(clusters[i]);
			for(j=0;j<sz(div[x]);j++)
			{
				ll d=div[x][j];
				for(ll lll=d;lll<2*d;lll++)
				{
					bool flag=true;
					for(ll k=lll;k<x;k+=d)
					{
						if(c[clusters[i][k]] != c[clusters[i][k-d]])
						{
							flag=false;
							break;
						}
					}
					if(flag)
						ans=min(ans, d);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}