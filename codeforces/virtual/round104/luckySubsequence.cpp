#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool lucky(ll x)
{
	if(x%10!=4 && x%10!=7)
		return false;
	while(x!=0)
	{
		x/=10;
		if(x==0)
			break;
		if(x%10!=4 && x%10!=7)
			return false; 
	}
	return true;
}

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
	ll n,k;
	cin>>n>>k;
	map<ll,ll> luckyOnes;
	ll i,val;
	ll unlucky=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		if(lucky(val))
			luckyOnes[val]++;
		else
			unlucky++;
	}
	ll ncr[100005]={0};
	ncr[0]=1;
	for(i=1;i<=k;i++)
	{
		if(i>unlucky)
			break;
		ncr[i]=divisionMod((ncr[i-1]*(unlucky-i+1))%mod,i);
	}
	ll dp[2005]={0};
	dp[0]=1;
	for(auto it=luckyOnes.begin();it!=luckyOnes.end();it++)
	{
		ll cnt=it->second;
		for(i=2000;i>=1;i--)
			dp[i]=(dp[i]+(dp[i-1]*cnt)%mod)%mod;
	}
	ll ans=0;
	ll j=0;
	for(i=k;i>=0;i--)
	{
		ans=(ans+(ncr[i]*dp[j])%mod)%mod;
		j++;
		if(j>=1500)
			break;
	}
	cout<<ans<<endl;
	return 0;
}