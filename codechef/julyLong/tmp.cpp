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
vector<ll> c(100005,0);
vector<ll> flag(100005,0);
vector<ll> blocked(100005,0);
vector<ll> ad[100005];

ll parent(ll x)
{
	if(p[x]==-1)
		return x;
	p[x]=parent(p[x]);
	return p[x];
}

void dfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(blocked[x]==1)
			blocked[v]=1;
	}
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(blocked[x]==1 || x==p)
			continue;
		if(blocked[v]==1)
		{
			blocked[x]=1;
			dfs(x,v);
		}
		else
		{
			flag[x]=-flag[v];
			dfs(x,v);
		}
	}
	return;
}

void dsu(ll v1,ll v2)
{
	ll x1=parent(v1);
	ll x2=parent(v2);
	if(x1==x2)
	{
		if(flag[v1]==flag[v2])
		{
			blocked[v1]=1;
			dfs(v1,0);
		}
	}
	else
	{
		if(blocked[v1]==1 && blocked[v2]==0)
		{
			blocked[v2]=1;
			dfs(v2,0);
		}
		else if(blocked[v2]==1 && blocked[v1]==0)
		{
			blocked[v1]=1;
			dfs(v1,0);
		}
		else if(blocked[v1]==0 && blocked[v2]==0)
		{
			if(flag[v1]==0 && flag[v2]==0)
			{
				flag[v1]=1;
				flag[v2]=-1;
				dfs(v1,0);
				dfs(v2,0);
			}
			else if(flag[v1]==0)
			{
				flag[v1]=-flag[v2];
				dfs(v1,0);
			}
			else if(flag[v2]==0)
			{
				flag[v2]=-flag[v1];
				dfs(v2,0);
			}
			else
			{
				if(flag[v1]==flag[v2])
				{
					flag[v1]=-flag[v2];
					dfs(v1,0);
				}
			}
			ad[v1].pb(v2);
			ad[v2].pb(v1);
			if(c[x1]<c[x2])
			{
				c[x2]+=c[x1];
				p[x1]=x2;
			}
			else
			{
				c[x1]+=c[x2];
				p[x2]=x1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(100005);
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
		else
		{
			ll x,y,v;
			cin>>x>>y>>v;
			ll x1=parent(x);
			ll x2=parent(y);
			if(x1!=x2 || blocked[x]==1 || blocked[y]==1 || blocked[x1]==1)
				cout<<"0\n";
			else
			{
				ll num=v*a[x];
				ll den=a[y];
				ll xx=__gcd(num,den);
				num/=xx;
				den/=xx;
				if(flag[x]!=flag[y])
					num=-num;
				cout<<num<<"/"<<den<<"\n";
			}
		}
	}
	// for(i=1;i<=n;i++)
	// 	cout<<flag[i]<<" ";
	// cout<<endl;
	// for(i=1;i<=n;i++)
	// 	cout<<blocked[i]<<" ";
	// cout<<endl;
	return 0;
}