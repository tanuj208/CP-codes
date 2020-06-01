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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	ll i;
	cin>>n>>m>>k;
	vector<ll> a,b;
	vector<pii> c;
	vector<ll> ad[n+2];
	for(i=0;i<n;i++)
	{
		ll aa,bb,cc;
		cin>>aa>>bb>>cc;
		a.pb(aa);
		b.pb(bb);
		c.pb(mp(cc,i));
	}
	sort(all(c));
	reverse(all(c));
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		u--;
		v--;
		ad[v].pb(u);
	}
	vector<ll> mx_cs(n+1);
	for(i=0;i<n;i++)
	{
		mx_cs[i] = i;
		ll j;
		for(j=0;j<sz(ad[i]);j++)
			mx_cs[i] = max(mx_cs[i], ad[i][j]);
	}

	vector<ll> mn_def(n+1);
	ll cur = k;
	for(i=0;i<n;i++)
	{
		if(cur < a[i])
		{
			cout<<-1<<endl;
			return 0;
		}
		mn_def[i] = cur-a[i];
		cur += b[i];
	}
	ll cur_mn = INT_MAX;
	for(i=n-1;i>=0;i--)
	{
		cur_mn = min(cur_mn, mn_def[i]);
		mn_def[i] = cur_mn;
	}
	for(i=0;i<n-1;i++)
		mn_def[i] = mn_def[i+1];
	mn_def[n-1] = cur;
	ll ans=0;

	for(i=0;i<n;i++)
	{
		ll imp = c[i].ff;
		ll idx = c[i].ss;
		idx = mx_cs[idx];
		if(mn_def[idx] == 0)
			continue;
		ll j;
		for(j=idx;j<n;j++)
			mn_def[j]--;
		for(j=idx-1;j>=0;j--)
			mn_def[j] = min(mn_def[j], mn_def[idx]);
		ans += imp;
	}
	cout<<ans<<endl;
	return 0;
}