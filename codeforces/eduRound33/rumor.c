#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

vector<ll> cost;
vector<ll> ad[100005];
vector<ll> visited(100005,-1);
ll mm;

ll dfs(ll v)
{
	// cout<<m<<endl;
	ll i;
	if(visited[v]!=-1)
		return 0;
	visited[v]=1;
	// cout<<m<<endl;
	mm=min(mm,cost[v-1]);
	for(i=0;i<sz(ad[v]);i++)
		ll temp=dfs(ad[v][i]);
	return mm;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		cost.pb(val);
	}
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		mm=INT_MAX;
		// cout<<m<<endl;
		ans+=dfs(i);
	}
	cout<<ans<<endl;
	return 0;
}