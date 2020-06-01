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

ll get_dist(pii p1, pii p2)
{
	return abs(p1.ff-p2.ff) + abs(p1.ss-p2.ss);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<pii> cor;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		cor.pb(mp(x,y));
	}
	vector<ll> c;
	ll total_cost=0;
	vector<ll>k;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		c.pb(val);
		total_cost+=val;
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		k.pb(val);
	}

	priority_queue<pii, vector<pii>, greater<pii>> p;

	for(i=0;i<n;i++)
		p.push(mp(c[i], i));

	vector<ll> con(n+5, -2); //-2 power station, else connected
	vector<ll> cost=c;
	vector<ll> vis(n+5, 0);
	vector<ll> main_stat(n+5);
	for(i=0;i<n;i++)
		main_stat[i]=i;

	while(!p.empty())
	{
		ll idx = p.top().ss;
		p.pop();
		if(vis[idx]==1)
			continue;
		vis[idx]=1;
		for(i=0;i<n;i++)
		{
			if(i==idx || i==con[idx] || main_stat[i]==main_stat[idx])
				continue;
			ll dist=get_dist(cor[i], cor[idx]);
			ll perkmcost = k[i]+k[idx];
			ll distcost = dist*perkmcost;
			if(distcost < cost[i])
			{
				total_cost-=cost[i];
				total_cost+=distcost;
				cost[i]=distcost;
				con[i]=idx;
				main_stat[i]=main_stat[idx];
				p.push(mp(distcost, i));
			}
		}
	}
	cout<<total_cost<<endl;
	vector<ll> v;
	vector<pii> e;
	for(i=0;i<n;i++)
	{
		if(con[i]==-2)
			v.pb(i+1);
		else
			e.pb(mp(i+1, 1+con[i]));
	}
	cout<<sz(v)<<endl;
	for(i=0;i<sz(v);i++)
		cout<<v[i]<<" ";
	cout<<endl;
	cout<<sz(e)<<endl;
	for(i=0;i<sz(e);i++)
		cout<<e[i].ff<<" "<<e[i].ss<<endl;
	return 0;
}