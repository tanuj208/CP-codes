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

vector<ll> ad[1005];
ll edge[1005][1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,s,t;
	cin>>n>>m>>s>>t;
	ll i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			edge[i][j]=0;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
		edge[v][u]=1;
		edge[u][v]=1;
	}
	queue<ll> q;
	q.push(s);
	vector<ll> dists(1005,LLONG_MAX);
	vector<ll> distt(1005,LLONG_MAX);
	vector<ll> vis(1005,0);
	dists[s]=0;
	while(!q.empty())
	{
		ll v=q.front();
		q.pop();
		if(vis[v]==1)
			continue;
		vis[v]=1;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			if(vis[x]==0)
			{
				dists[x]=min(dists[x],dists[v]+1);
				q.push(x);
			}
		}
	}
	for(i=0;i<=1000;i++)
		vis[i]=0;
	distt[t]=0;
	q.push(t);
	while(!q.empty())
	{
		ll v=q.front();
		q.pop();
		if(vis[v]==1)
			continue;
		vis[v]=1;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			if(vis[x]==0)
			{
				distt[x]=min(distt[x], distt[v]+1);
				q.push(x);
			}
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(edge[i][j]==1)
				continue;
			if(distt[i]+dists[j]+1 >= dists[t] && distt[j]+dists[i]+1 >= dists[t])
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}