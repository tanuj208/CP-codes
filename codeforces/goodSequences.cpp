#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> factors[100005];

void seive()
{
	ll i,j;
	for(i=2;i<=100000;i++)
		for(j=i;j<=100000;j+=i)
			factors[j].pb(i);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	seive();
	vector<ll> dp(100005,0);

	for(i=0;i<n;i++)
	{
		if(a[i]==1)
			continue;
		ll j;
		ll mx=1;
		for(j=0;j<sz(factors[a[i]]);j++)
		{
			ll x=factors[a[i]][j];
			mx=max(mx,1+dp[x]);
		}
		for(j=0;j<sz(factors[a[i]]);j++)
		{
			ll x=factors[a[i]][j];
			dp[x]=max(mx,dp[x]);
		}
	}
	ll ans=1;
	for(i=2;i<=100000;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}