#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> ad[300005];
vector<ll> subtree(300005,1);
ll flag=0;
ll found=-1;
ll parent=-1;
ll x,y;

void dfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll xx=ad[v][i];
		if(xx==p)
			continue;
		if(xx==y)
		{
			flag=1;
			parent=v;
		}
		dfs(xx,v);
		if(flag==1 && found==-1 && v==x)
			found=i;
		subtree[v]+=subtree[xx];
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n>>x>>y;
	ll i;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	if(n==1)
	{
		cout<<"0\n";
		return 0;
	}
	if(n==2)
	{
		cout<<"1\n";
		return 0;	
	}
	dfs(x,0);
	ll a=1,b=1;
	for(i=0;i<sz(ad[x]);i++)
	{
		if(i==found)
			continue;
		ll v=ad[x][i];
		a+=subtree[v];
	}
	for(i=0;i<sz(ad[y]);i++)
	{
		ll v=ad[y][i];
		if(v==parent)
			continue;
		b+=subtree[v];
	}
	cout<<(n*(n-1))-(a*b)<<endl;
	return 0;
}