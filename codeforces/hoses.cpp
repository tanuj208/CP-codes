#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> p(1004,-1);
vector<ll> c(1004,1),wi(1004,0),be(1004,0);

ll parent(ll x)
{
	if(p[x]==-1)
		return x;
	p[x]=parent(p[x]);
	return p[x];
}

void dsu(ll v1,ll v2)
{
	ll x1=parent(v1);
	ll x2=parent(v2);
	if(x1!=x2)
	{
		if(c[x1]<c[x2])
		{
			c[x2]+=c[x1];
			wi[x2]+=wi[x1];
			be[x2]+=be[x1];
			p[x1]=x2;
		}
		else
		{
			c[x1]+=c[x2];
			wi[x1]+=wi[x2];
			be[x1]+=be[x2];
			p[x2]=x1;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,W;
	cin>>n>>m>>W;
	vector<ll> wt,bt,value;
	ll i,j,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		wt.pb(val);
		wi[i+1]=val;
	}
	for(i=0;i<n;i++)
	{
		cin>>val;
		bt.pb(val);
		be[i+1]=val;
	}
	for(i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		dsu(x,y);
	}
	vector<ll> grps[1004];
	for(i=1;i<=n;i++)
	{
		ll x=parent(i);
		grps[x].pb(i);
	}
	vector<ll> op(1004,0); // op[i] --> max beauty at weight i
	ll ans=0;
	ll z;
	for(i=1;i<=n;i++)
	{
		ll sumw=0;
		ll sumb=0;
		vector<ll> tmp=op;
		for(j=0;j<sz(grps[i]);j++)
		{
			ll ind=grps[i][j]-1;
			sumw+=wt[ind];
			sumb+=bt[ind];
			for(z=1;z<=W;z++)
			{
				if(wt[ind]>z)
					continue;
				else
					tmp[z]=max(tmp[z],op[z-wt[ind]]+bt[ind]);
			}
		}
		for(z=1;z<=W;z++)
		{
			if(sumw>z)
				continue;
			else
				tmp[z]=max(tmp[z],op[z-sumw]+sumb);
		}
		op=tmp;
	}
	for(i=1;i<=W;i++)
		ans=max(ans,op[i]);
	cout<<ans<<endl;
	return 0;
}