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

vector<ll> vis[200005];
vector<ll> ad[200005];
ll ans=0;

ll dfs(ll v)
{
	ll i;
	vis[v][sz(vis[v])-1]=1;
	ll mx=0;
	ll smx=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(sz(vis[x])==0 || vis[x][sz(vis[x])-1]==1)
			continue;
		ll tmp=dfs(x);
		if(tmp>mx)
			mx=tmp,smx=mx;
		else if(tmp>smx)
			smx=tmp;
	}
	ans=max(ans,mx+smx+1);
	return mx+1;
}

ll diameter(ll n)
{
	ll an=0;
	ll i;
	for(i=1;i<=n;i++)
	{
		// cerr<<i<<endl;
		if(sz(vis[i])==0 || vis[i][sz(vis[i])-1]==1)
			continue;
		// cerr<<i<<endl;
		ll tmp=dfs(i);
		an=max(an,ans);
	}
	return an;
}

// vector<ll> primes;
vector<ll> prime(200005,1);
vector<ll> tmp[20005];
vector<ll> fac[200005];

void pre()
{
	ll i,j;
	for(i=2;i<=200000;i++)
	{
		if(prime[i]==0)
			continue;
		for(j=i;j<=200000;j+=i)
		{
			fac[j].pb(i);
			if(j!=i)
				prime[j]=0;
		}
	}
	ll cnt=1;
	for(i=2;i<=200000;i++)
	{
		if(prime[i]==1)
		{
			prime[i]=cnt;
			cnt++;
		}
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
	vector<ll> a;
	a.pb(0);
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=1;i<n;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	pre();
	// cerr<<"FDLJF"<<endl;
	ll j;
	for(i=1;i<=n;i++)
	{
		// cout<<a[i]<<"DFJL"<<endl;
		for(j=0;j<sz(fac[a[i]]);j++)
		{
			ll x=fac[a[i]][j];
			// cout<<x<<endl;
			tmp[prime[x]].pb(i);
		}
	}
	ll final=0;
	// cerr<<"LDFKJF"<<endl;
	for(i=1;i<=20000;i++)
	{
		// if(i==1)
		// 	cout<<sz(tmp[i])<<endl;
		for(j=0;j<sz(tmp[i]);j++)
		{
			ll v=tmp[i][j];
			vis[v].pb(0);
		}
		final=max(final,diameter(n));
	}
	cout<<final<<endl;
	return 0;
}