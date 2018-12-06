#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (ll)(a).size()
#define m 1000000007
#define p 31

ll power[5003];
string s;
ll len;

void calculatePower()
{
	ll i;
	power[0]=1;
	for(i=1;i<=5000;i++)
		power[i]=(power[i-1]*p)%m;
	return;
}

ll forHash[5003];
ll revHash[5003];

ll val(char a)
{
	return (ll)a-(ll)('a')+1;
}

void hashh()
{
	ll i;
	forHash[0]=(power[1]*val(s[0]))%m;
	for(i=1;i<len;i++)
		forHash[i]=(forHash[i-1]+(val(s[i])*power[i+1])%m)%m;
	revHash[len-1]=(p*val(s[len-1]))%m;
	for(i=len-2;i>=0;i--)
		revHash[i]=(revHash[i+1]+(val(s[i])*power[len-i])%m)%m;
	return;
}

ll dp[5003][5003];

ll ans(ll l, ll r)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l>r)
		return 0;
	if(l==r)
	{
		dp[l][r]=1;
		return 1;
	}
	ll flag=0;
	// ll mid=(l+r)/2;
	if(((forHash[r]-forHash[l-1])/power[l-1])==((revHash[l]-revHash[r+1])/power[len-r]))
		flag=1;
	cout<<"l="<<l<<" r="<<r<<" flag="<<flag<<endl;
	dp[l][r]=ans(l+1,r)+ans(l,r-1)-ans(l+1,r-1)+flag;
	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	// cout<<val(s[0])
	len=sz(s);
	ll q;
	cin>>q;
	ll i,j;
	calculatePower();
	hashh();
	for(i=0;i<5003;i++)
	{
		for(j=0;j<5003;j++)
		{
			dp[i][j]=-1;
		}
	}
	calculatePower();
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<ans(l,r)<<endl;
	}
	return 0;
}