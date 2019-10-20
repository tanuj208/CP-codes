#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll n;
ll mod=1000000007;
ll dp[5005][5005]={0};
string s;

ll value(char a)
{
	return (ll)a-'a'+1;
}


void calculate(ll i,ll j)
{
	if(i>j)
		return;
	if(dp[i][j]!=-1)
		return;
	bool x;
	calculate(i+1,j-1);
	if(dp[i+1][j-1]==0 || s[i]!=s[j])
		x=false;
	else
		x=true;
	if(x==false)
		dp[i][j]=0;
	else
	{
		ll mid=(i+j)/2;
		if((j-i+1)%2==0)
		{
			calculate(i,mid);
			dp[i][j]=1+dp[i][mid];
		}
		else
		{
			calculate(i,mid-1);
			dp[i][j]=1+dp[i][mid-1];
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,j;
	cin>>s;
	n=sz(s);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=-1;
	for(i=0;i<n;i++)
	{
		dp[i][i]=1;
		if(i!=n-1 && s[i]==s[i+1])
			dp[i][i+1]=2;
		else
			dp[i][i+1]=0;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i<=j)
				calculate(i,j);
	ll ans[5005]={0};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i<=j)
				ans[dp[i][j]]++;
	for(i=n-2;i>=0;i--)
		ans[i]+=ans[i+1];
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}