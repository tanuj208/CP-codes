#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<pii> ad[55];
vector<ll> flag(55,0);
ll mn=INT_MAX;
ll ans=0;
ll n;

void calculate()
{
	ll i;
	priority_queue <pii,vector<pii>,greater<pii> > q1,q2;
	vector<ll> visited(55,0);
	for(i=1;i<=n;i++)
	{
		if(flag[i]==1)
			q1.push(mp(0,i));
		else
			q2.push(mp(0,i));
	}
	ll dist[55];
	for(i=1;i<=n;i++)
	{
		if(flag[i]==1)
			dist[i]=0;
		else
			dist[i]=INT_MAX;
	}
	while(!q1.empty())
	{
		ll v=q1.top().second;
		q1.pop();
		if(visited[v]==1)
			continue;
		visited[v]=1;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i].first;
			ll w=ad[v][i].second;
			if(dist[x]>dist[v]+w)
			{
				dist[x]=dist[v]+w;
				q1.push(mp(dist[x],x));
			}
		}
	}
	ll tmp=0;
	for(i=1;i<=n;i++)
		tmp+=dist[i],visited[i]=0;
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
			dist[i]=0;
		else
			dist[i]=INT_MAX;
	}
	while(!q2.empty())
	{
		ll v=q2.top().second;
		q2.pop();
		if(visited[v]==1)
			continue;
		visited[v]=1;
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i].first;
			ll w=ad[v][i].second;
			if(dist[x]>dist[v]+w)
			{
				dist[x]=dist[v]+w;
				q2.push(mp(dist[x],x));
			}
		}
	}
	for(i=1;i<=n;i++)
		tmp+=dist[i];
	if(mn>tmp)
	{
		mn=tmp;
		ans=1;
	}
	else if(mn==tmp)
		ans++;
	return;
}

void rec(ll i)
{
	if(i>n)
		return;
	rec(i+1);
	flag[i]=1;
	calculate();
	rec(i+1);
	flag[i]=0;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll zz=1;
	for(zz=1;zz<=t;zz++)
	{
		ll i,j;
		mn=INT_MAX;
		ans=0;
		cout<<"Case #"<<zz<<": ";
		ll v,e;
		cin>>v>>e;
		n=v;
		for(i=1;i<=n;i++)
			flag[i]=0;
		for(i=1;i<=n;i++)
			ad[i].clear();
		for(i=0;i<e;i++)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			ad[a].pb(mp(b,c));
			ad[b].pb(mp(a,c));
		}
		rec(1);
		cout<<ans<<"\n";
	}
	return 0;
}