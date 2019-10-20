#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> a(100005);
vector<ll> dist(100005,0);
vector<ll> p(100005,-1);
vector<ll> c(100005,1);
vector<ll> blocked(100005,0);

pii parent(ll x)
{
	if(p[x]==-1)
		return mp(x,dist[x]);

	pii tmp=parent(p[x]);

	if(blocked[p[x]]==1 || blocked[x]==1)
		blocked[x]=1,blocked[p[x]]=1;
	else
		dist[x]=(tmp.second+dist[x])%2;

	p[x]=tmp.first;
	return mp(p[x],dist[x]);
}

void dsu(ll v1,ll v2)
{
	ll x1=parent(v1).first;
	ll x2=parent(v2).first;
	if(x1==x2)
	{
		if((dist[v1]+dist[v2])%2==0)
			blocked[x1]=1;
	}
	else
	{
		if(blocked[x1]==1 || blocked[x2]==1)
		{
			blocked[x1]=1;
			blocked[x2]=1;
		}
		if(c[x1]<c[x2])
		{
			p[x1]=x2;
			c[x1]+=c[x2];
			dist[x1]=(dist[v1]+dist[v2]+1)%2;
		}
		else
		{
			p[x2]=x1;
			c[x2]+=c[x1];
			dist[x2]=(dist[v1]+dist[v2]+1)%2;
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
	ll i,val;
	for(i=1;i<=n;i++)
		cin>>a[i];
	while(m--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll x,y;
			cin>>x>>y;
			a[x]=y;
		}
		else if(t==2)
		{
			ll x,y;
			cin>>x>>y;
			dsu(x,y);
		}
		else if(t==3)
		{
			ll x,y,v;
			cin>>x>>y>>v;
			ll x1=parent(x).first;
			ll x2=parent(y).first;
			if(x1!=x2 || blocked[x1]==1 || blocked[x]==1 || blocked[y]==1)
				cout<<"0\n";
			else
			{
				ll num=v*a[x];
				ll den=a[y];
				ll xx=__gcd(num,den);
				num/=xx;
				den/=xx;
				if((dist[x]+dist[y])%2==1)
					num=-num;
				cout<<num<<"/"<<den<<"\n";
			}
		}
	}
	return 0;
}