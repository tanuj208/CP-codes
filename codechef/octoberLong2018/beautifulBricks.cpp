#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll divisionMod(ll a, ll b)
{
	ll val=1;
	ll power=mod-2;
	while(power!=0)
	{
		if(power%2==1)
		{
			val=(val*b)%mod;
		}
		b=b*b;
		b=b%mod;
		power=power/2;
	}
	return (a*val)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll ii;
	ll p[1005];
	p[0]=1;
	for(ii=1;ii<=1000;ii++)
		p[ii]=(p[ii-1]*2)%mod;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll dp[k+5][k+5];   // dp[i][j]==> n-iCj
		ll i,j;
		for(i=0;i<=k;i++)
			for(j=0;j<=k;j++)
				dp[i][j]=0;
		for(i=0;i<=k;i++)
			dp[i][0]=1;
		for(j=1;j<=k;j++)
			dp[k][j]=(dp[k][j-1]*divisionMod(n-k-j+1,j))%mod;
		for(i=k-1;i>=0;i--)
			for(j=1;j<=k;j++)
				dp[i][j] = (dp[i+1][j] + dp[i+1][j-1])%mod;
		ll ans=0;
		for(i=1;i<=k;i++)
		{
			if(n-i+1<i)
				continue;
			ans = (ans + (p[i]*dp[i-1][i])%mod)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}