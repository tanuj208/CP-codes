#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> p(100005,-1);
vector<ll> szz(100005,1);
vector<ll> ad[100005];
vector<ll> level(100005,0);
ll a[100005][30]; // stores (2^j)th ancestor of i
ll n;

void dfs(ll v,ll pp)
{
	ll i;
	if(v!=1)
		p[v]=pp;
	if(v==1)
		level[v]=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==pp)
			continue;
		level[x]=1+level[v];
		dfs(x,v);
		szz[v]+=szz[x];
	}
	return;
}

void precalculation()
{
	ll i,j;
	for(i=1;i<=n;i++)
		for(j=0;j<=28;j++)
			a[i][j]=-1;
	for(i=2;i<=n;i++)
		a[i][0]=p[i];
	for(j=1;(1<<j)<=n;j++)
		for(i=1;i<=n;i++)
			if(a[i][j-1]!=-1)
				a[i][j]=a[a[i][j-1]][j-1];
	return;
}

pii lcaLength(ll pp,ll q)
{
	ll ans=0;
	if(level[pp]<level[q])
	{
		ll temp=pp;
		pp=q;
		q=temp;
	}
	ll x=25;
	ll i,j;
	for(j=x;j>=0;j--)
	{
		if(a[pp][j]==-1)
			continue;
		if(level[a[pp][j]]>=level[q])
		{
			pp=a[pp][j];
			ans+=(1<<j);
		}
	}
	if(pp==q)
		return mp(pp,ans);
	for(j=x;j>=0;j--)
	{
		if(a[pp][j]==-1 || a[q][j]==-1)
			continue;
		if(a[pp][j]!=a[q][j])
		{
			pp=a[pp][j];
			q=a[q][j];
			ans+=(2*(1<<j));
		}
	}
	return mp(p[pp],ans+2);
}

ll func(ll q,ll len)
{
	ll x=25;
	ll j;
	for(j=x;j>=0;j--)
	{
		if(a[q][j]!=-1)
		{
			if((1<<j)<len)
			{
				q=a[q][j];
				len-=(1<<j);
			}
		}
	}
	return q;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		ll aa,b;
		cin>>aa>>b;
		ad[aa].pb(b);
		ad[b].pb(aa);
	}
	dfs(1,0);
	precalculation();
	ll m;
	cin>>m;
	while(m--)
	{
		ll t,y;
		cin>>t>>y;
		if(t==y)
		{
			cout<<n<<endl;
			continue;
		}
		ll len=lcaLength(t,y).second;
		if(len%2==1)
			cout<<"0\n";
		else
		{
			if(level[t]<level[y])
			{
				ll temp=t;
				t=y;
				y=temp;
			}
			ll x=func(t,len/2);
			if(level[t]==level[y])
			{
				ll x2=func(y,len/2);
				cout<<n-szz[x]-szz[x2]<<endl;
				continue;
			}
			cout<<szz[p[x]]-szz[x]<<endl;
		}
	}
	return 0;
}