#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll destroyed[200005]={0};
vector<pii> ad[200005];
vector<ll> tempad[200005];
vector<ll> order;
vector<ll> level(200005,0);

void leveldfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(tempad[v]);i++)
	{
		if(tempad[v][i]!=p)
		{
			leveldfs(tempad[v][i],v);
			level[v]=max(level[v],1+level[tempad[v][i]]);
		}
	}
	return;
}

void dfs(ll v,ll p)
{
	ll i;
	if(destroyed[v]==0 && destroyed[p]==1 && sz(ad[v])%2==1)
	{
		order.pb(v);
		destroyed[v]=1;
	}
	if(destroyed[v]==0 && destroyed[p]==0 && sz(ad[v])%2==0)
	{
		cout<<v<<" "<<p<<endl;
		order.pb(v);
		destroyed[v]=1;
		if(p!=0)
		{
			order.pb(p);
			destroyed[p]=1;
		}
	}
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i].second;
		if(x!=p)
			dfs(x,v);
		if(destroyed[v]==1 && sz(ad[v])%2==1 && destroyed[p]==0 && p!=0)
		{
			destroyed[p]=1;
			order.pb(p);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	destroyed[0]=0;
	for(i=1;i<=n;i++)
	{
		ll val;
		cin>>val;
		if(val!=0)
		{
			tempad[i].pb(val);
			tempad[val].pb(i);
		}
	}
	leveldfs(1,0);
	for(i=1;i<=n;i++)
	{
		for(ll j=0;j<sz(tempad[i]);j++)
		{
			ll x=tempad[i][j];
			ad[i].pb(mp(level[x],x));
		}
		sort(ad[i].begin(),ad[i].end());
		reverse(ad[i].begin(),ad[i].end());
	}
	dfs(1,0);
	dfs(1,0);
	if(sz(order)<n)
		cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		for(i=0;i<n;i++)
			cout<<order[i]<<"\n";
	}
	return 0;
}