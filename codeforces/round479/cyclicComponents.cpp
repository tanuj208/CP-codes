#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll ans=0;

vector<ll> ad[200005];
vector<ll> visited(200005,0);
ll xx;
ll nhiHoPaega=0;

void dfs(ll v,ll p)
{
	// cout<<v<<endl;
	if(visited[v]==1)
		return;
	ll i;
	visited[v]=1;
	if(sz(ad[v])!=2)
		nhiHoPaega=1;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		if(x==xx && nhiHoPaega==0)
			ans++;
		dfs(x,v);
	}
	return;
}

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
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	for(i=1;i<=n;i++)
	{
		nhiHoPaega=0;
		xx=i;
		dfs(i,0);
	}
	cout<<ans<<endl;
	return 0;
}