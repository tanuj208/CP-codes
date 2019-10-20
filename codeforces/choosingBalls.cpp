#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> c,v,dp(100005,LLONG_MIN);
ll mx=1;
ll secondmx=2;
ll n,q;

void query(ll a,ll b)
{
	ll i;
	for(i=0;i<n;i++)
	{
		ll color=c[i];
		ll val=v[i];
		if(dp[color]!=LLONG_MIN)
			dp[color]=max(dp[color],dp[color]+a*val);
		if(mx==color)
		{
			ll xx=dp[secondmx];
			if(xx<0)
				xx=0;
			dp[color]=max(dp[color],xx+b*val);
		}
		else
		{
			ll xx=dp[mx];
			if(xx<0)
				xx=0;
			ll tmp=xx+b*val;
			dp[color]=max(dp[color],tmp);
			if(dp[color]>dp[mx])
				secondmx=mx,mx=color;
			else if(dp[color]>dp[secondmx])
				secondmx=color;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		v.pb(val);
	}
	for(i=0;i<n;i++)
	{
		cin>>val;
		c.pb(val);
	}
	while(q--)
	{
		mx=1;
		secondmx=2;
		ll a,b;
		cin>>a>>b;
		query(a,b);
		ll ans=0;
		for(i=1;i<=n;i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
		for(i=1;i<=n;i++)
			dp[i]=LLONG_MIN;
	}
	return 0;
}