#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[5003];
vector<ll> inDegree(5003,0);
vector<ll> visited(5003,0);
ll n,m,s;

void dfs(ll v)
{
	if(visited[v]==1)
		return;
	visited[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		dfs(x);
	}
	return;
}

bool cond()
{
	ll i;
	for(i=1;i<=n;i++)
		if(visited[i]==0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>s;
	ll i;
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		inDegree[b]++;
	}
	dfs(s);
	set<pii> x;
	ll ans=0;
	for(i=1;i<=n;i++)
		x.insert(mp(inDegree[i],i));
	while(cond()==false)
	{
		ll v=x.begin()->second;
		if(visited[v]!=1)
		{
			ans++;
			dfs(v);
		}
		x.erase(x.begin());
	}
	cout<<ans<<endl;
	return 0;
}