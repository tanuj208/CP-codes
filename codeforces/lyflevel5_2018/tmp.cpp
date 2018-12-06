#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=998244353;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	ll ans=1;
	cin>>n;
	map<ll,ll> xx;
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	ll j;
	vector<ll> big;
	vector<ll> ff(1005,0);
	for(i=0;i<n;i++)
	{
		ll x=a[i];
		ll fff=0;
		for(j=2;j<=100000;j++)
		{
			while(x%j==0)
			{
				xx[j]++;
				x/=j;
				fff=1;
			}
		}
		if(fff==1 && x!=1)
			ff[sz(big)]=1;			
		if(x!=1)
			big.pb(x);
	}
	for(i=0;i<sz(big);i++)
	{
		if(big[i]==1)
			continue;
		ll x=sqrt(big[i]);
		if(x*x==big[i])
		{
			xx[x]+=2;
			big[i]=1;
			for(j=i+1;j<sz(big);j++)
			{
				while(big[j]%x==0)
				{
					ff[j]=1;
					big[j]/=x;
					xx[x]++;
				}
			}
			continue;
		}
		x=cbrt(big[i]);
		if(x*x*x==big[i])
		{
			xx[x]+=3;
			big[i]=1;
			for(j=i+1;j<sz(big);j++)
			{
				while(big[j]%x==0)
				{
					ff[j]=1;
					big[j]/=x;
					xx[x]++;
				}
			}
			continue;
		}
		ll flag=0;
		ll factorr=1;
		for(j=i+1;j<sz(big);j++)
		{
			if(big[j]==big[i])
			{
				big[j]=1;
				factorr++;
				continue;
			}
			x=__gcd(big[i],big[j]);
			if(x!=1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			ll y=big[i]/x;
			xx[x]+=factorr;
			if(y!=1)
				xx[y]++;
			else
				y=LLONG_MAX;
			big[i]=1;
			for(j=i+1;j<sz(big);j++)
			{
				while(big[j]%x==0)
				{
					ff[j]=1;
					big[j]/=x;
					xx[x]++;
				}
				while(big[j]%y==0)
				{
					ff[j]=1;
					big[j]/=y;
					xx[y]++;
				}
			}
		}
		else
		{
			big[i]=1;
			if(ff[i]==1)
				ans=(ans*(1+factorr))%mod;
			else
				ans=(ans*(1+factorr)*(1+factorr))%mod;
		}
	}
	for(auto it=xx.begin();it!=xx.end();it++)
	{
		ans=(ans*(it->second+1))%mod;
	}
	cout<<ans<<"\n";
	cout.flush();
	return 0;
}