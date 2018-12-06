#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> ad[100005];
ll ans=0;
vector<ll> size(100005,1);

void dfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		dfs(x,v);
		size[v]+=size[x];
		if(size[x]%2==0)
			ans++;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	if(n%2==1)
	{
		cout<<"-1\n";
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}