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
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n,m;
		cin>>n>>m;
		vector<ll> nnodes(n+1);
		nnodes[1] = 0;
		ll i;
		for(i=1;i<n;i++)
		{
			ll val;
			cin>>val;
			nnodes[i+1] = -val;
		}
		vector<pii> e;
		vector<pii> ad[n+1];
		for(i=0;i<m;i++)
		{
			ll u,v;
			cin>>u>>v;
			e.pb(mp(u,v));
			ad[v].pb(mp(u,i));
			ad[u].pb(mp(v,i));
		}
		vector<ll> ans(m+1, -1);
		priority_queue <pair<pii,pii>,vector<pair<pii,pii>>,greater<pair<pii,pii>> > q;
		vector<ll> dis(n+1, -1);
		dis[1] = 0;
		for(i=0;i<sz(ad[1]);i++)
		{
			ll x = ad[1][i].ff;
			ll idx = ad[1][i].ss;
			q.push(mp(mp(nnodes[x], idx), mp(1,x)));
		}
		ll cur = 1;
		ll cur_ans = 1;
		while(!q.empty())
		{
			pair<pii,pii> tp = q.top();
			q.pop();
			if(dis[tp.ss.ss] != -1 && ans[tp.ff.ss] == -1)
				ans[tp.ff.ss] = 1000000;
			if(dis[tp.ss.ss] != -1)
				continue;
			// cout<<tp.ss.ff<<" "<<tp.ss.ss<<" "<<tp.ff.ff<<endl;
			if(tp.ff.ff != cur)
			{
				cur = tp.ff.ff;
				cur_ans++;
			}
			dis[tp.ss.ss] = cur_ans;
			// cout<<cur_ans<<" "<<dis[tp.ss.ff]<<endl;
			ans[tp.ff.ss] = cur_ans - dis[tp.ss.ff];
			// cout<<tp.ff.ss<<"F"<<ans[tp.ff.ss]<<endl;
			ll v = tp.ss.ss;
			for(i=0;i<sz(ad[v]);i++)
			{
				ll x = ad[v][i].ff;
				ll i2 = ad[v][i].ss;
				if(dis[x] != -1 && ans[i2] == -1)
				{
					ans[i2] = 1000000;
					continue;
				}
				q.push(mp(mp(nnodes[x], i2), mp(v, x)));
			}
		}
		for(i=0;i<m;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}