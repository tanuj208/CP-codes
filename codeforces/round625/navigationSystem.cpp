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

vector<ll> min_path[200005];
vector<ll> min_dist(200005, INT_MAX);
vector<ll> vis(200005, 0);
vector<ll> ad[200005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[v].pb(u); // reverse ad list
	}
	ll k;
	cin>>k;
	vector<ll> path;
	for(i=0;i<k;i++)
	{
		ll val;
		cin>>val;
		path.pb(val);
	}

	ll dest = path[k-1];
	min_dist[dest]=0;

	queue<pii> q;
	q.push(mp(dest, 0));
	while(!q.empty())
	{
		pii xx = q.front();
		ll vtx=xx.ff;
		ll dist = xx.ss;
		vis[vtx]=1;
		q.pop();
		for(i=0;i<sz(ad[vtx]);i++)
		{
			ll x=ad[vtx][i];
			if(min_dist[x] >= dist+1)
			{
				min_dist[x]=dist+1;
				min_path[x].pb(vtx);
			}
			if(vis[x]==0)
			{
				vis[x]=1;
				q.push(mp(x,dist+1));
			}
		}
	}

	for(i=1;i<=n;i++)
	{
		sort(all(min_path[i]));
		// for(ll j=0;j<sz(min_path[i]);j++)
		// 	cout<<min_path[i][j]<<" ";
		// cout<<endl;
	}

	ll mn_ans=0,mx_ans=0;

	for(i=0;i<k-1;i++)
	{
		ll cur=path[i];
		ll next=path[i+1];
		if(binary_search(all(min_path[cur]), next))
		{
			if(sz(min_path[cur])>1)
				mx_ans++;
		}
		else
		{
			mx_ans++;
			mn_ans++;
		}
	}
	cout<<mn_ans<<" "<<mx_ans<<endl;

	return 0;
}