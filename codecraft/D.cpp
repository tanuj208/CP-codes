#include <bits/stdc++.h>
using namespace std;

long long mod=1000000007;

long long power(long long x, long long y) 
{
	long long temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

long long dpp[100005]={0};
long long dp[53][53]={0};
long long p[100005];
long long tmp[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	long long i,j,k;
	cin>>s;
	long long n = (long long)s.size();
	long long constant=1;
	vector<long long> cnt(53,0);

	p[0]=1;
	for(i=1;i<=n;i++)
		p[i]=(p[i-1]*i)%mod;
	for(i=0;i<n;i++)
	{
		char c = s[i];
		if(c>='a' && c<='z')
			cnt[c-'a']++;
		else
			cnt[c-'A' + 26]++;
	}
	constant = (p[n/2] * p[n/2])%mod;
	long long den = 1;
	for(i=0;i<52;i++)
	    den = (den * p[cnt[i]])%mod;
	constant = (constant * power(den, mod-2))%mod;

	dpp[0]=1;
	for(i=0;i<52;i++)
	{
		long long x=cnt[i];
		if(x==0)
			continue;
		for(j=n;j>=x;j--)
			dpp[j]=(dpp[j]+dpp[j-x])%mod;
	}

	for(i=0;i<52;i++)
	{
		for(j=0;j<52;j++)
		{
			if(i==j)
				continue;
			for(i=0;i<=n;i++)
				tmp[i]=dpp[i];
			long long x1=cnt[i];
			long long x2=cnt[j];
			for(k=x1;k<=n;k++)
				tmp[k]=(tmp[k]-tmp[k-x1]+mod)%mod;
			for(k=x2;k<=n;k++)
				tmp[k]=(tmp[k]-tmp[k-x2]+mod)%mod;
			dp[i][j]=tmp[n/2];
		}
	}
	long long q;
	cin>>q;
	while(q--)
	{
		long long indi,indj;
		long long u,v;
		cin>>u>>v;
		u--;
		v--;
		if(s[u]>='a' && s[u]<='z')
			indi=s[u]-'a';
		else
			indi=s[u]-'A'+26;
		if(s[v]>='a' && s[v]<='z')
			indj=s[v]-'a';
		else
			indj=s[v]-'A'+26;
		long long ans=1;
		if(indi!=indj)
		{
			ans=(constant*dp[indi][indj])%mod;
			ans = (2 * ans)%mod;
		}
		else
			ans = (constant * dpp[n/2])%mod;
		cout<<ans<<"\n";
	}
	return 0;
}