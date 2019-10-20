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

ll mod=998244353;

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

vector<ll> ad[300005];
vector<ll> vis(300005,0);
vector<ll> vis2(300005,0);
vector<bool> even(300005);

ll dfs(ll v, ll flag) // other end status
{
	if(flag==1)
		vis[v]=1;
	else
		vis2[v]=1;
	ll i;
	ll ans;
	if(even[v])
		ans=2;
	else
		ans=1;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if((flag==1 && vis[x]==1) || (flag==2 && vis2[x]==1))
		{
			if(even[v]==even[x])
				return 0;
			else
				continue;
		}
		even[x]=!even[v];
		ans = (ans * dfs(x, flag))%mod;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll i;
		for(i=0;i<=n;i++)
		{
			ad[i].clear();
			vis[i]=0;
			vis2[i]=0;
		}
		for(i=0;i<m;i++)
		{
			ll u,v;
			cin>>u>>v;
			ad[u].pb(v);
			ad[v].pb(u);
		}
		ll ans=1;
		for(i=1;i<=n;i++)
		{
			if(vis[i]==1)
				continue;
			even[i]=true;
			ll tmp = dfs(i, 1);
			even[i]=false;
			tmp = (tmp + dfs(i, 2))%mod;
			ans=(ans*tmp)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}