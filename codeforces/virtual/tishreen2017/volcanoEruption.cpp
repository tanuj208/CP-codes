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
vector<ll> lll(1005,1);
vector<pair<pii,ll> > c;  // ((y,x),r)

void reset()
{
	ll i;
	c.clear();
	for(i=0;i<1004;i++)
		p[i]=-1,lll[i]=1;
}

ll parent(ll x)
{
	if(p[x]==-1)
		return x;
	p[x]=parent(p[x]);
	return p[x];
}

void dsu(ll i,ll j)
{
	ll x1=parent(i);
	ll y1=parent(j);
	if(x1==y1)
		return;
	if(lll[x1]<=lll[y1])
	{
		p[x1]=y1;
		lll[y1]+=lll[x1];
	}
	else
	{
		p[y1]=x1;
		lll[x1]+=lll[y1];
	}
	return;
}

bool check(ll x1,ll y1,ll r1,ll x2,ll y2,ll r2)
{
	if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1+r2)*(r1+r2))
		return true;
	else
		return false;
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
		reset();
		ll n,w,l;
		cin>>n>>w>>l;
		ll i,j;
		for(i=0;i<n;i++)
		{
			ll x,y,r;
			cin>>x>>y>>r;
			c.pb(mp(mp(y,x),r));
		}
		sort(c.begin(),c.end());
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(check(c[i].first.second,c[i].first.first,c[i].second,c[j].first.second,c[j].first.first,c[j].second))
					dsu(i,j);
		}
		vector<vector<ll> > x;
		for(i=0;i<n;i++)
		{
			vector<ll> tmp;
			for(j=0;j<n;j++)
				if(parent(j)==i)
					tmp.pb(j);
			if(sz(tmp)!=0)
				x.pb(tmp);
		}
		ll ans=0;
		for(i=0;i<sz(x);i++)
		{
			ll L=w;
			ll R=0;
			for(j=0;j<sz(x[i]);j++)
			{
				ll ind=x[i][j];
				L=min(L,c[ind].first.second-c[ind].second);
				R=max(R,c[ind].first.second+c[ind].second);
			}
			if(L<=0 && R>=w)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}