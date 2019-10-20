#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

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

vector<pair<pii,ll> > ad[300005];
vector<pii> ad2[300005];
vector<ll> d(300005,LLONG_MAX);
vector<pii> x(300005);
vector<ll> vis(300005,0);

void dijkstra()
{
	priority_queue <pii,vector<pii>,greater<pii> > p;
	p.push(mp(0,1));
	d[1]=0;
	while(!p.empty())
	{
		ll i;
		ll v=(p.top()).second;
		if(vis[v]==1)
		{
			p.pop();
			continue;
		}
		vis[v]=1;
		ll wt=(p.top()).first;
		p.pop();
		for(i=0;i<sz(ad[v]);i++)
		{
			ll xx =ad[v][i].first.first;
			ll totalwt=wt+ad[v][i].first.second;
			if(totalwt<d[xx])
			{
				d[xx]=totalwt;
				x[xx] = mp(v,ad[v][i].second);
				p.push(mp(d[xx],xx));
			}
		}
	}
	return;
}

vector<ll> vis2(300005,0);
ll cnt=0;
ll k;

void dfs(ll v)
{
	ll i;
	vis2[v]=1;
	for(i=0;i<sz(ad2[v]);i++)
	{
		ll xx=ad2[v][i].first;
		if(vis2[xx]==1)
			continue;
		cnt++;
		cout<<ad2[v][i].second<<" ";
		if(cnt==k)
			return;
		dfs(xx);
		if(cnt==k)
			return;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m>>k;
	ll i;
	for(i=0;i<m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		ad[x].pb(mp(mp(y,w), i+1));
		ad[y].pb(mp(mp(x,w), i+1));
	}
	dijkstra();
	for(i=2;i<=n;i++)
	{
		ad2[i].pb(mp(x[i].first,x[i].second));
		ad2[x[i].first].pb(mp(i,x[i].second));
	}
	if(k>=n-1)
	{
		cout<<n-1<<endl;
		for(i=2;i<=n;i++)
		{
			cout<<x[i].second<<" ";
		}
		cout<<endl;
		return 0;
	}
	cout<<k<<endl;
	if(k==0)
		return 0;
	dfs(1);
	cout<<endl;
	return 0;
}