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
	if(y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

void get_shor(vector<vector<ll>>& shor, ll v, vector<vector<ll>>& ad, ll n)
{
	vector<ll> vis(n+5, 0);
	queue<pii> q;
	q.push(mp(v, 0));
	while(!q.empty())
	{
		pii xx=q.front();
		ll x=xx.ff;
		ll dist = xx.ss;
		q.pop();
		if(vis[x]==1)
			continue;
		vis[x]=1;
		shor[v][x]=dist;
		ll i;
		for(i=1;i<=n;i++)
			if(ad[x][i]==1)
				q.push(mp(i, dist+1));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<vector<ll>> ad(n+5, vector<ll>(n+5, INT_MAX));
	ll i,j;
	for(i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(j=1;j<=n;j++)
		{
			if(s[j-1]=='0')
				ad[i][j]=0;
			else
				ad[i][j]=1;
		}
	}
	ll m;
	cin>>m;
	vector<ll> path;
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		path.pb(val);
	}
	vector<vector<ll>> shor(n+5, vector<ll>(n+5, INT_MAX));
	for(i=1;i<=n;i++)
		get_shor(shor, i, ad, n);
	vector<ll> ans;
	ll curV = path[0];
	ll curD = 0;
	ll lastV = path[0];
	ans.pb(path[0]);
	// cout<<path[4]<<"FLJ"<<endl;
	for(i=0;i<m;i++)
	{
		ll v=path[i];
		if(shor[lastV][v]!=shor[curV][v]+curD)
		{
			ans.pb(path[i-1]);
			lastV = path[i-1];
			curD = 0;
		}
		curD += shor[curV][v];
		curV = v;
	}
	ans.pb(path[m-1]);
	cout<<sz(ans)<<endl;
	for(i=0;i<sz(ans);i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}