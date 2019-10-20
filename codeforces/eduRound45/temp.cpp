#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n;
vector<pair<ll,pii> > a(200005);
vector<ll> b(200005,0);
vector<ll> ans(200005,0);
vector<ll> fac[200005];
vector<ll> divi[200005];
map<ll,ll> p,c;

void sieve()
{
	ll i,j;
	for(i=2;i<=200000;i++)
		for(j=i;j<=200000;j+=i)
			fac[j].pb(i);
}

ll parent(ll x)
{
	if(p.find(x)==p.end())
		return x;
	p[x]=parent(p[x]);
	return p[x];
}

ll child(ll x)
{
	if(c.find(x)==c.end())
		return 1;
	else
		return c[x];
}

void dsu(ll x,ll i)
{
	ll v1=a[x].second.first;
	ll v2=a[x].second.second;
	ll x1=parent(v1);
	ll x2=parent(v2);
	if(x1==x2)
		return;
	else
	{
		ll xx1=child(x1);
		ll xx2=child(x2);
		ans[i]+=(xx1*xx2);
		if(xx1<=xx2)
		{
			if(p.find(x1)==p.end())
				p.insert(mp(x1,x2));
			else
				p[x1]=x2;
			if(c.find(x2)==c.end())
				c.insert(mp(x2,1+xx1));
			else
				c[x2]+=xx1;
		}
		else
		{
			if(p.find(x2)==p.end())
				p.insert(mp(x2,x1));
			else
				p[x2]=x1;
			if(c.find(x1)==c.end())
				c.insert(mp(x1,1+xx2));
			else
				c[x1]+=xx2;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,val;
	for(i=1;i<=n;i++)
		cin>>b[i];
	for(i=1;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[i]=mp(__gcd(b[x],b[y]),mp(x,y));
	}
	sieve();
	for(i=1;i<n;i++)
	{
		ll x=a[i].first;
		for(ll j=0;j<sz(fac[x]);j++)
			divi[fac[x][j]].pb(i);
	}
	for(i=2;i<=200005;i++)
	{
		ll j;
		for(j=0;j<sz(divi[i]);j++)
		{
			ll x=divi[i][j];
			dsu(x,i);
		}
		p.clear();
		c.clear();
	}
	for(i=100000;i>=2;i--)
		for(ll j=2*i;j<=200000;j+=i)
			ans[i]-=ans[j];
	ll sum=0;
	for(i=1;i<=n;i++)
		ans[b[i]]++;
	for(i=2;i<=200000;i++)
		sum+=ans[i];
	ll xxxx=((n*(n-1))/2)+n-sum;
	if(xxxx!=0)
		cout<<"1 "<<xxxx<<endl;
	for(i=2;i<=200000;i++)
		if(ans[i]!=0)
			cout<<i<<" "<<ans[i]<<"\n";
	return 0;
}