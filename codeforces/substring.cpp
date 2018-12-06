#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,m;
string s;
vector<ll> ad[300005];
vector<ll> inDegree(300005,0);
vector<ll> visited(300005,0);
vector<ll> on(300005,0);
ll ans[300005][30];

void dfs(ll v)
{
	visited[v]=1;
	on[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(on[x]==1)
		{
			cout<<"-1\n";
			exit(0);
		}
		if(visited[x]==0)
			dfs(x);
		ll j;
		for(j=0;j<26;j++)
			ans[v][j]=max(ans[v][j],ans[x][j]);
	}
	on[v]=0;
	ans[v][ll(s[v-1]-'a')]++;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	cin>>s;
	ll i,j;
	ll infiniteAns=0;
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(a==b)
			infiniteAns=1;
		ad[a].pb(b);
		inDegree[b]++;
	}
	ll flag=0;
	for(i=1;i<=n;i++)
	{
		if(inDegree[i]==0)
			flag=1;
	}
	if(flag==0)
		infiniteAns=1;
	for(i=1;i<=n;i++)
		for(j=0;j<26;j++)
			ans[i][j]=0;
	ll anss=0;
	for(i=1;i<=n;i++)
	{
		if(inDegree[i]==0)
			dfs(i);
		for(j=0;j<26;j++)
			anss=max(anss,ans[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			infiniteAns=1;
	}
	if(infiniteAns==1)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<anss<<endl;
	return 0;
}