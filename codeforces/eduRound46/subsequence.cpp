#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=998244353;
ll dp[1003][1003];

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

ll ncr(ll n,ll r)
{
	if(r<0 || n<0 || r>n)
		return 0;
	if(dp[n][r]!=-1)
		return dp[n][r];
	if(n==r || r==0)
	{
		dp[n][r]=1;
		return 1;
	}
	dp[n][r]=divisionMod((n*ncr(n-1,r-1))%mod,r);
	return dp[n][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i,val,j;
	vector<ll> a;
	vector<ll> ans(1003,0);
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			dp[i][j]=-1;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=n-2;i>=0;i--)
	{
		ans[i]=ans[i+1];
		if(a[i]<=0)
			continue;
		for(j=i+a[i];j<n;j++)
			ans[i]=(ans[i]+((ans[j+1]+1)*(ncr(j-i,a[i])-ncr(j-i-1,a[i])+mod)%mod))%mod;
	}
	cout<<ans[0]<<endl;
	return 0;
}