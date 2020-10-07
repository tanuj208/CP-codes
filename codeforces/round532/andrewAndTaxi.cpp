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

vector<pair<pii,ll> > ad[100005];
vector<ll> ad2[100005];
ll n,m;
vector<ll> vis(100005,0);
vector<ll> mark(100005,0);

bool dfs(ll v)
{
	vis[v]=1;
	ll i;
	mark[v]=1;
	for(i=0;i<sz(ad2[v]);i++)
	{
		ll x=ad2[v][i];
		if(mark[x]==1)
		{
			return false;
		}
		if(vis[x]==1)
			continue;
		if(!dfs(x))
			return false;
	}
	mark[v]=0;
	return true;
}

bool valid(ll x)
{
	ll i,j;
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
		mark[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		ad2[i].clear();
		for(j=0;j<sz(ad[i]);j++)
			if(ad[i][j].ff.ss>x)
				ad2[i].pb(ad[i][j].ff.ff);
	}
	for(i=1;i<=n;i++)
		if(vis[i]!=1 && !dfs(i))
			return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i,j;
	for(i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ad[a].pb(mp(mp(b,c), i));
	}

	ll l=1;
	ll r=1000000000;
	ll mid=(l+r)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if(valid(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	while(valid(mid) && mid>=1)
		mid--;
	while(!valid(mid) && mid<=1000000000)
		mid++;

	for(i=1;i<=n;i++)
	{
		ad2[i].clear();
		for(j=0;j<sz(ad[i]);j++)
			if(ad[i][j].ff.ss>mid)
				ad2[i].pb(ad[i][j].ff.ff);
	}

	vector<ll> inDeg(100005,0);
	for(i=1;i<=n;i++)
		for(j=0;j<sz(ad2[i]);j++)
			inDeg[ad2[i][j]]++;

	queue<ll> q;
	for(i=1;i<=n;i++)
		if(inDeg[i]==0)
			q.push(i);

	vector<ll> topSort(100005, INT_MAX);
	ll pos=0;

	while(!q.empty())
	{
		ll v=q.front();
		q.pop();
		topSort[v]=pos;
		pos++;
		for(i=0;i<sz(ad2[v]);i++)
		{
			ll x=ad2[v][i];
			inDeg[x]--;
			if(inDeg[x]==0)
				q.push(x);
		}
	}
	vector<ll> ans;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<sz(ad[i]);j++)
		{
			if(ad[i][j].ff.ss<=mid)
			{
				ll x=ad[i][j].ff.ff;
				if(topSort[i]>topSort[x])
					ans.pb(ad[i][j].ss);
			}
		}
	}
	cout<<mid<<" "<<sz(ans)<<endl;
	for(i=0;i<sz(ans);i++)
		cout<<ans[i]+1<<" ";
	cout<<endl;
	return 0;
}