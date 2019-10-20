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

vector<ll> visited(100005,0);
vector<pii> ad[100005];
vector<ll> d(100005,1e15);
priority_queue <pii,vector<pii>,greater<pii> > pp;

void dijkstra()
{
	while(!pp.empty())
	{
		ll i;
		ll v=(pp.top()).second;
		// cout<<v<<endl;
		if(visited[v]==1)
		{
			pp.pop();
			continue;
		}
		visited[v]=1;
		ll wt=(pp.top()).first;
		pp.pop();
		for(i=0;i<sz(ad[v]);i++)
		{
			ll totalwt=max(wt, ad[v][i].second);
			if(totalwt<d[ad[v][i].first])
			{
				d[ad[v][i].first]=totalwt;
				pp.push(mp(d[ad[v][i].first],ad[v][i].first));
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k;
	vector<ll> x;
	cin>>n>>m>>k;
	ll special[100005]={0};
	ll sp;
	ll i;
	for(i=0;i<k;i++)
	{
		ll val;
		cin>>val;
		sp=val;
		special[val]=1;
	}
	sort(x.begin(),x.end());
	for(i=0;i<m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		ad[u].pb(mp(v,w));
		ad[v].pb(mp(u,w));
	}
	d[sp]=0;
	pp.push(mp(0,sp));
	dijkstra();
	ll ans=0;
	for(i=1;i<=n;i++)
		if(special[i]==1)
			ans=max(ans,d[i]);
	for(i=0;i<k;i++)
		cout<<ans<<" ";
	cout<<endl;
	return 0;
}