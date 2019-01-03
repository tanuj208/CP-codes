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

vector<ll> w;
vector<pii> ad[300005];
ll ans=0;

ll dfs(ll v,ll p)
{
	ll i;
	vector<ll> tmp;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].first;
		ll length = ad[v][i].second;
		if(x==p)
			continue;
		tmp.pb(dfs(x,v)-length);
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	ll maxx=0;
	if(sz(tmp)==0)
	{
		ans=max(ans, w[v]);
		return w[v];
	}
	else if(sz(tmp)==1)
	{
		tmp[0]=max((ll)0, tmp[0]);
		ans=max(ans, tmp[0]+w[v]);
		if((tmp[0]+w[v])>0)
			return tmp[0]+w[v];
	}
	else
	{
		ll mxVal = max((ll)0, tmp[0]);
		ll secMxVal = max(tmp[1], (ll)0);
		ans=max(ans, mxVal+secMxVal+w[v]);
		return mxVal+w[v];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	w.pb(0);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		w.pb(val);
	}
	for(i=0;i<n-1;i++)
	{
		ll u,v,c;
		cin>>u>>v>>c;
		ad[u].pb(mp(v,c));
		ad[v].pb(mp(u,c));
	}
	ll tmp=dfs(1,0);
	cout<<ans<<endl;
	return 0;
}