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
vector<ll> col[3];
vector<ll> vs;
ll n;

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

ll rec(ll c1, ll c2, ll c3)
{
	// cerr<<c1<<" "<<c2<<" "<<c3<<endl;
	ll ans=0;
	ll i;
	for(i=0;i<sz(vs);i++)
	{
		ll curC;
		if(i%3==0)
			curC=c1;
		else if(i%3==1)
			curC=c2;
		else
			curC=c3;
		ll v=vs[i];
		// cerr<<v<<endl;
		ans+=col[curC][v];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,j;
	for(j=0;j<3;j++)
	{
		col[j].pb(-1); // garbage
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			col[j].pb(val);
		}
	}
	vector<ll> ad[100005];
	vector<ll> deg(100005,0);
	for(i=0;i<n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	ll v = -1;
	for(i=1;i<=n;i++)
	{
		if(deg[i]>2)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(deg[i]==1)
			v=i;
	}
	vector<ll> vis(1e5+5, 0);
	vis[v]=1;
	vs.pb(v);
	while(true)
	{
		bool flag=true;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			if(vis[x]==0)
			{
				vis[x]=1;
				v=x;
				vs.pb(x);
				flag=false;
			}
		}
		if(flag)
			break;
	}
	// for(i=0;i<sZ())
	ll ans=LLONG_MAX;
	ll x;
	ll c1,c2,c3;
	x=rec(0,1,2);
	if(ans>x)
	{
		ans=x;
		c1=0;
		c2=1;
		c3=2;
	}
	x=rec(0,2,1);
	if(ans>x)
	{
		ans=x;
		c1=0;
		c2=2;
		c3=1;
	}
	x=rec(1,0,2);
	if(ans>x)
	{
		ans=x;
		c1=1;
		c2=0;
		c3=2;
	}
	x=rec(1,2,0);
	if(ans>x)
	{
		ans=x;
		c1=1;
		c2=2;
		c3=0;
	}
	x=rec(2,0,1);
	if(ans>x)
	{
		ans=x;
		c1=2;
		c2=0;
		c3=1;
	}
	x=rec(2,1,0);
	if(ans>x)
	{
		ans=x;
		c1=2;
		c2=1;
		c3=0;
	}
	cout<<ans<<endl;
	vector<ll> cols(1e5+5);
	for(i=0;i<sz(vs);i++)
	{
		ll x=vs[i];
		if(i%3==0)
			cols[x]=c1+1;
		else if(i%3==1)
			cols[x]=c2+1;
		else
			cols[x]=c3+1;
	}
	for(i=1;i<=n;i++)
		cout<<cols[i]<<" ";
	cout<<endl;
	return 0;
}