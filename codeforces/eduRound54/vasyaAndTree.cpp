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

vector<ll> d(300005);
vector<ll> ad[300005];
vector<pii> q[300005];  // second is value
vector<ll> xx(300005,0);
vector<ll> ans(300005,0);
ll sum=0;
ll m;
ll mx=-1;

void dfs1(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		d[x]=d[v]+1;
		mx=max(mx,d[x]);
		dfs1(x,v);
	}
	return;
}

void dfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(q[v]);i++)
	{
		if(d[v]+q[v][i].first>mx)
			xx[mx+1]+=q[v][i].second;
		else
			xx[d[v]+q[v][i].first]+=q[v][i].second;
		sum+=q[v][i].second;
	}
	ans[v]+=sum;
	sum-=xx[d[v]];
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		dfs(x,v);

	}
	sum+=xx[d[v]];
	for(i=0;i<sz(q[v]);i++)
	{
		if(d[v]+q[v][i].first>mx)
			xx[mx+1]-=q[v][i].second;
		else
			xx[d[v]+q[v][i].first]-=q[v][i].second;
		sum-=q[v][i].second;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	for(i=1;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		ad[x].pb(y);
		ad[y].pb(x);
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		ll v,d,x;
		cin>>v>>d>>x;
		q[v].pb(mp(d,x));
	}
	d[1]=1;
	dfs1(1,0);
	dfs(1,0);
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}