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
vector<ll> ad[100];
ll ans1=0,ans2=0;
vector<ll> a;

void dfs(ll v,ll fac)
{
	ans2+=fac*a[v-1];
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		dfs(x,fac*2);
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
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		ans1+=val;
	}
	cout<<ans1<<" ";
	for(i=1;i<=n;i++)
	{
		ll j,k;
		cin>>k;
		for(j=1;j<=k;j++)
		{
			ll val;
			cin>>val;
			ad[i].pb(val);
		}
	}
	dfs(1,1);
	cout<<ans2<<endl;
	return 0;
}