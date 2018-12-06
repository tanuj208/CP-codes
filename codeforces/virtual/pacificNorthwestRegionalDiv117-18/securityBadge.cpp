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

vector<pair<ll,pii> > ad[5005];
set<ll> possible;
ll vis[1005];
ll s,t;
ll ans=0;

ll dfs(ll v, ll x, ll y)
{
	if(x>y)
		return 0;
	if(v==t)
		return 1;
	if(vis[v]!=-1)
		return vis[v];
	vis[v]=0;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll xx=ad[v][i].first;
		ll x1=ad[v][i].second.first;
		ll y1=ad[v][i].second.second;
		ll tmp=0;
		if(x1<=x && y1>=y)
			tmp=dfs(xx,x,y);
		if(tmp==1)
		{
			vis[v]=1;
			break;
		}
	}
	return vis[v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	cin>>n>>m>>k;
	cin>>s>>t;
	ll i;
	for(i=0;i<m;i++)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ad[a].pb(mp(b, mp(c,d)));
		possible.insert(c);
		possible.insert(d);
	}
	for(auto it=possible.begin();it!=possible.end();it++)
	{
		memset(vis, -1, sizeof(vis));
		ll a1=*it;
		ll tmp=dfs(s, a1,a1);
		if(tmp==1)
			ans++;
		it++;
		if(it==possible.end())
			break;
		ll b1=*it;
		it--;
		memset(vis, -1, sizeof(vis));
		tmp=dfs(s,a1+1,b1-1);
		if(tmp==1)
			ans+=(b1-a1-1);
	}
	cout<<ans<<endl;
	return 0;
}