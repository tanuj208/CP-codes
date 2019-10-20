#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[100005];
queue<ll> q;
vector<ll> a[105];
ll dist[100005][105];    // min cost of reaching jth ingredient in ith town

void bfs(ll g)
{
	ll j;
	for(j=0;j<sz(a[g]);j++)
		dist[a[g][j]][g]=0,q.push(a[g][j]);
	while(!q.empty())
	{
		ll v=q.front();
		q.pop();
		for(j=0;j<sz(ad[v]);j++)
		{
			ll x=ad[v][j];
			if(dist[x][g]==LLONG_MAX)
			{
				dist[x][g]=dist[v][g]+1;
				q.push(x);
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
	ll n,m,k,s;
	cin>>n>>m>>k>>s;
	ll i,val,j;
	for(i=0;i<=100000;i++)
		for(j=0;j<=100;j++)
			dist[i][j]=LLONG_MAX;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a[val].pb(i+1);
	}
	for(i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		ad[x].pb(y);
		ad[y].pb(x);
	}
	for(i=1;i<=k;i++)
		bfs(i);
	for(i=1;i<=n;i++)
	{
		sort(dist[i]+1,dist[i]+(k+1));
		ll ans=0;
		for(j=1;j<=s;j++)
			ans+=dist[i][j];
		cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}