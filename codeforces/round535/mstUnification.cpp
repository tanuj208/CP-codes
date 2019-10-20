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

vector<pii> ad[200005];
vector<pair<ll, pii> > ed;
vector<ll> p(200005,-1);
vector<ll> c(200005,0);
vector<ll> flag(200005,0);

ll parent(ll x)
{
	if(p[x]==-1)
		return x;
	p[x]=parent(p[x]);
	return p[x];
}
// map<ll,ll> x;

bool cycle(ll u,ll v)
{
	ll x1=parent(u);
	ll x2=parent(v);
	if(x1==x2)
		return true;
	else
		return false;
}

void addEdge(ll u,ll v)
{
	ll x1=parent(u);
	ll x2=parent(v);

	if(c[x1]<=c[x2])
	{
		p[x1]=x2;
		c[x2]+=c[x1];
	}
	else
	{
		p[x2]=x1;
		c[x1]+=c[x2];
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
	for(i=0;i<m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		ad[u].pb(mp(v,w));
		ad[v].pb(mp(u,w));
		ed.pb(mp(w,mp(u,v)));
		// x[w]++;
	}
	ll ans=0;
	sort(ed.begin(),ed.end());
	for(i=0;i<m;i++)
	{
		ll w=ed[i].ff;
		ll j=i;
		while(ed[j].ff==w && j<m)
		{
			if(cycle(ed[j].ss.ff, ed[j].ss.ss))
				flag[j]=1;
			j++;
		}
		j=i;
		while(ed[j].ff==w && j<m)
		{
			if(flag[j]==1)
			{
				j++;
				continue;
			}
			flag[j]=1;
			if(cycle(ed[j].ss.ff, ed[j].ss.ss))
				ans++;
			else
				addEdge(ed[j].ss.ff, ed[j].ss.ss);
			j++;
		}
		i=j-1;
	}
	cout<<ans<<endl;
	return 0;
}