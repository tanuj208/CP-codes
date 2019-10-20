#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> ad[205];

bool dfs(ll v,ll a)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==a)
			return true;
		if(dfs(x,a))
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	map<string,ll> x;
	ll cntr=1;
	ll i;
	for(i=0;i<n;i++)
	{
		string a,b,c,d,e;
		ll v1,v2;
		cin>>a>>b>>c>>d>>e;
		if(x.find(a)==x.end())
		{
			x[a]=cntr;
			cntr++;
		}
		v1=x[a];
		if(x.find(e)==x.end())
		{
			x[e]=cntr;
			cntr++;
		}
		v2=x[e];
		ad[v1].pb(v2);
	}
	for(i=0;i<m;i++)
	{
		string a,c,d,e,b;
		cin>>a>>c>>d>>e>>b;
		ll v1,v2;
		if(x.find(a)==x.end() || x.find(b)==x.end())
		{
			cout<<"Pants on Fire\n";
			continue;
		}
		v1=x[a];
		v2=x[b];
		if(dfs(v1,v2))
			cout<<"Fact\n";
		else if(dfs(v2,v1))
			cout<<"Alternative Fact\n";
		else
			cout<<"Pants on Fire\n";
	}
	return 0;
}