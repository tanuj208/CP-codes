#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[104];
vector<ll> visited(105,0);
vector<ll> on(105,0);
ll cycles=0;

void dfs(ll v,ll p)
{
	if(visited[v]!=0)
		return;
	visited[v]=1;
	on[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		if(on[x]==1)
		{
			cycles++;
			continue;
		}
		dfs(x,v);
	}
	on[v]=0;
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
	dfs(1,0);
	bool ans=true;
	if(cycles!=1)
		ans=false;
	for(i=1;i<=n;i++)
		if(visited[i]==0)
			ans=false;
	if(ans==false)
		cout<<"NO\n";
	else
		cout<<"FHTAGN!\n";
	return 0;
}