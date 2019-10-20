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
vector<ll> vis1(5005, 0), vis2(5005, 0);
ll n,m;
vector<pii> ad[5005];

bool dfs(ll v)
{
	if(vis2[v]==1)
		return true;
	if(vis1[v]==1)
		return false;
	vis1[v]=1;
	vis2[v]=1;
	ll i;
	bool ans=false;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].ff;
		bool tmp = dfs(x);
		ans = ans|tmp;
	}
	vis2[v]=0;
	return ans;
}
vector<ll> col(5005, 0);
vector<ll> vis3(5005, 0);

void dfs2(ll v, ll cur_col)
{
	if(vis3[v]==1)
		return;
	vis3[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].ff;
		ll xx=ad[v][i].ss;
		if(cur_col==1)
		{
			col[xx]=2;
			dfs2(x,2);
		}
		else
		{
			col[xx]=1;
			dfs2(x,1);
		}
		if(vis3[x]==1)
			continue;
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
	vector<ll> indeg(n+5,0);
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(mp(v, i));
		indeg[v]++;
	}
	vector<ll> V;
	for(i=1;i<=n;i++)
		if(indeg[i]==0)
			V.pb(i);
	bool ans=false;
	for(i=1;i<=n;i++)
		ans=ans|dfs(i);
	if(!ans)
	{
		cout<<1<<endl;
		for(i=0;i<m;i++)
			cout<<1<<" ";
		cout<<endl;
		return 0;
	}
	for(i=0;i<sz(V);i++)
		dfs2(V[i], 1);
	for(i=1;i<=n;i++)
		if(vis3[i]==0)
			dfs2(i, 1);
	cout<<2<<endl;
	for(i=0;i<m;i++)
		cout<<col[i]<<" ";
	cout<<endl;

	return 0;
}