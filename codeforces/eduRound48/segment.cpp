#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll dp[1005][1005];
string s,t;

ll func(ll l,ll r)
{
	if(l>r)
	{
		dp[l][r]=0;
		return 0;
	}
	if(l==r && dp[l][r]==-1)
	{
		dp[l][r]=0;
		return 0;
	}
	if(dp[l][r]!=-1)
		return dp[l][r];
	dp[l][r]=func(l,r-1)+func(l+1,r)-func(l+1,r-1);
	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,q;
	cin>>n>>m>>q;
	cin>>s>>t;
	ll i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			dp[i][j]=-1;
	for(i=0;i<n;i++)
	{
		ll tmp=i;
		ll flag=0;
		for(j=0;j<m;j++)
		{
			if(s[i]==t[j])
				i++;
			else
			{
				flag=1;
				break;
			}
		}
		i=tmp;
		if(flag==0)
			dp[i+1][i+m]=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ll tmp=func(i,j);
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<dp[l][r]<<"\n";
	}
	return 0;
}