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
	ll flagg[502]={0};
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	map<ll,ll> cubes;
	for(i=1;i<=1260000;i++)
		cubes[i*i*i]=i;
	ll j;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
			continue;
		ll x=sqrt(a[i]);
		if(x*x==a[i])
		{
			ll y=sqrt(x);
			if(y*y==x)
			{
				xx[y]+=4;
				x=y;
			}
			else
				xx[x]+=2;
			for(j=i+1;j<n;j++)
			{
				while(a[j]%x==0)
				{
					flagg[j]=1;
					a[j]/=x;
					xx[x]++;
				}
			}
			a[i]=1;
			continue;
		}
		if(cubes.find(a[i])!=cubes.end())
		{
			x=cubes[a[i]];
			xx[x]+=3;
			for(j=i+1;j<n;j++)
			{
				while(a[j]%x==0)
				{
					flagg[j]=1;
					a[j]/=x;
					xx[x]++;
				}
			}
			a[i]=1;
			continue;
		}
		ll flag=0;
		ll fac=1;
		for(j=i+1;j<n;j++)
		{
			if(a[j]==a[i])
				continue;
			x=__gcd(a[i],a[j]);
			if(x!=1)
			{
				flag=1;
				break;
			}
		}
		for(j=i+1;j<n;j++)
		{
			if(a[j]==a[i])
			{
				fac++;
				a[j]=1;
			}
		}
		if(flag==1)
		{
			ll y=a[i]/x;
			if(y==1)
				y=LLONG_MAX;
			else
				xx[y]+=fac;
			xx[x]+=fac;
			for(j=i+1;j<n;j++)
			{
				if(a[j]==a[i])
					continue;
				while(a[j]%x==0)
				{
					flagg[j]=1;
					a[j]/=x;
					xx[x]++;
				}
				while(a[j]%y==0)
				{
					flagg[j]=1;
					a[j]/=y;
					xx[y]++;
				}
			}
			a[i]=1;
		}
		else
		{
			if(flagg[i]==1)
				ans=(ans*(1+fac))%mod;
			else
				ans=(((ans*(1+fac))%mod)*(1+fac))%mod;
			a[i]=1;
		}
	}
	for(auto it=xx.begin();it!=xx.end();it++)
		ans=(ans*(it->second+1))%mod;
	cout<<ans<<"\n";
	cout.flush();
	return 0;
}