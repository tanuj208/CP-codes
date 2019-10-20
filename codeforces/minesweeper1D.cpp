#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll dp[1000005][6]; // 3->bomb // 4-> bomb then 1
string s;
ll n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=sz(s);
	if(s[0]=='2' || s[n-1]=='2')
	{
		cout<<"0\n";
		return 0;
	}
	if(s[0]=='0')
		dp[0][0]=1;
	else if(s[0]=='1')
		dp[0][1]=1;
	else if(s[0]=='2');
	else if(s[0]=='*')
		dp[0][3]=1;
	else if(s[0]=='?')
	{
		dp[0][0]=1;
		dp[0][1]=1;
		dp[0][3]=1;
	}
	for(ll i=1;i<n;i++)
	{
		if(s[i]=='0')
			dp[i][0]=(dp[i-1][0]+dp[i-1][4])%mod;
		else if(s[i]=='1')
			dp[i][1]=(dp[i-1][0]+dp[i-1][4])%mod,dp[i][4]=dp[i-1][3];
		else if(s[i]=='2')
			dp[i][2]=dp[i-1][3];
		else if(s[i]=='*')
			dp[i][3]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
		else if(s[i]=='?')
		{
			dp[i][0]=(dp[i-1][0]+dp[i-1][4])%mod;
			dp[i][1]=(dp[i-1][0]+dp[i-1][4])%mod;
			dp[i][2]=dp[i-1][3];
			dp[i][3]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
			dp[i][4]=dp[i-1][3];
		}
	}
	cout<<(dp[n-1][0]+dp[n-1][3]+dp[n-1][4])%mod<<endl;
	return 0;
}