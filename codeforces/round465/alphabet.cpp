#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1000000007;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

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

ll s1[100005],s2[100005];
ll n,m;
ll ans=0;

void answer(ll i, ll num, ll den)
{
	num=num%mod;
	den=den%mod;
	ll temp=divisionMod(num,den);
	if(i==n)
		return;
	if(s1[i]==s2[i] && s1[i]!=0)
		answer(i+1,num,den);

	if(s1[i]>s2[i] && s2[i]!=0)
		ans=(ans+temp)%mod;

	if(s1[i]<s2[i] && s1[i]!=0)
		return;

	if(s1[i]==0 && s2[i]!=0)
	{
		ans=(ans+(temp*divisionMod((m-s2[i]),m))%mod)%mod;
		answer(i+1,num,den*m);
	}

	if(s1[i]!=0 && s2[i]==0)
	{
		ans=(ans+(temp*divisionMod(s1[i]-1,m))%mod)%mod;
		answer(i+1,num,den*m);
	}

	if(s1[i]==0 && s2[i]==0)
	{
		ans=(ans+(temp*divisionMod(m-1,2*m))%mod)%mod;
		answer(i+1,num,den*m);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	for(i=0;i<n;i++)
		cin>>s1[i];
	for(i=0;i<n;i++)
		cin>>s2[i];
	answer(0,1,1);
	cout<<ans%mod<<endl;
	// cout<<(divisionMod(99,200)*divisionMod(101010101,100000000))%mod<<endl;
	return 0;
}
		