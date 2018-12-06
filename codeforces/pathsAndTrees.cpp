#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pair<ll,pii> > ad[300005];
vector<ll> data(300005);
vector<ll> dist(300005,LLONG_MAX);
vector<ll> visited(300005,0);
vector<ll> edge(300005);

void dijsktra(ll u)
{
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(mp(0,u));
	dist[u]=0;
	data[u]=0;
	while(!q.empty())
	{
		pii w=q.top();
		q.pop();
		ll wt=w.first;
		ll v=w.second;
		if(visited[v]==1)
			continue;
		visited[v]=1;
		ll i;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i].first;
			ll wtt=ad[v][i].second.first;
			ll edgeNum=ad[v][i].second.second;
			if(dist[x]>wtt+wt)
			{
				dist[x]=wtt+wt;
				data[x]=edgeNum;
				q.push(mp(dist[x],x));
			}
			else if(dist[x]==wtt+wt)
			{
				if(edge[data[x]]>edge[edgeNum])
				{
					data[x]=edgeNum;
					visited[x]=0;
					q.push(mp(dist[x],x));
				}
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
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=1;i<=m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ad[a].pb(mp(b,mp(c,i)));
		ad[b].pb(mp(a,mp(c,i)));
		edge[i]=c;
	}
	edge[0]=LLONG_MAX;
	ll u;
	cin>>u;
	dijsktra(u);
	vector<ll> ans;
	ll anss=0;
	for(i=1;i<=n;i++)
	{
		if(i==u)
			continue;
		ans.pb(data[i]);
		anss+=edge[data[i]];
	}
	cout<<anss<<endl;
	for(i=0;i<n-1;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}