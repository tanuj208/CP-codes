#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> p(1005,-1);
vector<ll> c(1005,1);
ll shortest[1005][1005];
vector<ll> ad[1005];
ll ans=0;

ll parent(ll v)
{
	if(p[v]==-1)
		return v;
	p[v]=parent(p[v]);
	return p[v];
}

void dfs(ll v1,ll p,ll v2)
{
	ll i;
	for(i=0;i<sz(ad[v1]);i++)
	{
		ll x=ad[v1][i];
		if(x==p)
			continue;
		shortest[v2][x]=min(shortest[v1][v2],shortest[x][v1]);
		shortest[x][v2]=shortest[v2][x];
		dfs(x,v1,v2);
	}
	return;
}

void insert(ll v1,ll v2,ll w)
{
	ll x1=parent(v1);
	ll x2=parent(v2);
	if(x1!=x2)
	{
		if(c[x1]>c[x2])
		{
			p[v2]=x1;
			c[x1]+=c[x2];
		}
		else
		{
			p[v1]=x2;
			c[x2]+=c[x1];
		}
		shortest[v1][v2]=w;
		shortest[v2][v1]=w;
		ll i;
		dfs(v1,0,v2);
		dfs(v2,0,v1);
		ad[v1].pb(v2);
		ad[v2].pb(v1);
	}
	else
		ans+=2*(shortest[v1][v2]-w);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll mat[1005][1005];
		ll n;
		cin>>n;
		vector<pair<ll,pii> > wts;
		ll i,j;
		for(i=0;i<1003;i++)
			for(j=0;j<1003;j++)
				shortest[i][j]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				ll val;
				cin>>val;
				mat[i][j]=val;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				ans+=abs(mat[i][j]-mat[j][i]);
				mat[i][j]=max(mat[i][j],mat[j][i]);
				mat[j][i]=mat[i][j];
				if(i<=j)
					wts.pb(mp(mat[i][j],mp(i+1,j+1)));
			}
		}
		sort(wts.begin(),wts.end());
		reverse(wts.begin(),wts.end());
		for(i=0;i<sz(wts);i++)
		{
			ll w=wts[i].first;
			ll v1=wts[i].second.first;
			ll v2=wts[i].second.second;
			insert(v1,v2,w);
		}
		cout<<ans<<endl;
		for(i=0;i<1003;i++)
		{
			p[i]=-1;
			c[i]=1;
			ad[i].clear();
		}
		ans=0;
	}
	return 0;
}