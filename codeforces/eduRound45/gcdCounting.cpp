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
vector<ll> a(200005,0);
vector<ll> ans(2000005,0);
vector<vector<ll> > ad(200005);
map<ll,ll> gcds[200005];

void dfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x!=p)
		{
			dfs(x,v);
			for(map<ll,ll>:: iterator j=gcds[v].begin();j!=gcds[v].end();j++)
				for(map<ll,ll>:: iterator k=gcds[x].begin();k!=gcds[x].end();k++)
					ans[__gcd(j->first,k->first)]+=(j->second*k->second);

			for(map<ll,ll>:: iterator j=gcds[x].begin();j!=gcds[x].end();j++)
			{
				ll aa=__gcd(j->first,a[v]);
				ll bb=j->second;
				gcds[v][aa]+=bb;
				ans[aa]+=bb;
			}
			gcds[x].clear();
		}
	}
	gcds[v][a[v]]++;
	ans[a[v]]++;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		ad[x].pb(y);
		ad[y].pb(x);
	}
	dfs(1,0);
	for(i=1;i<=200000;i++)
		if(ans[i]>0)
			cout<<i<<" "<<ans[i]<<"\n";
	return 0;
}