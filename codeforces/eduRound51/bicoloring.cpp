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
	ll n,z;
	cin>>n>>z;
	ll dp[1004][2005][4];   // ith column j number of components k types of coloring of ith column
	ll i,j,k;
	for(i=0;i<=1000;i++)
		for(j=0;j<=2000;j++)
			for(k=0;k<4;k++)
				dp[i][j][k]=0;
	dp[1][1][0]=1;
	dp[1][1][1]=1;
	dp[1][2][2]=1;
	dp[1][2][3]=1;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=2*i;j++)
		{
			dp[i+1][j][0]+=dp[i][j][0];
			dp[i+1][j+1][1]+=dp[i][j][0];
			dp[i+1][j+1][2]+=dp[i][j][0];
			dp[i+1][j+1][3]+=dp[i][j][0];

			dp[i+1][j][0]%=mod;
			dp[i+1][j+1][1]%=mod;
			dp[i+1][j+1][2]%=mod;
			dp[i+1][j+1][3]%=mod;

			dp[i+1][j][1]+=dp[i][j][1];
			dp[i+1][j+1][0]+=dp[i][j][1];
			dp[i+1][j+1][2]+=dp[i][j][1];
			dp[i+1][j+1][3]+=dp[i][j][1];

			dp[i+1][j][1]%=mod;
			dp[i+1][j+1][0]%=mod;
			dp[i+1][j+1][2]%=mod;
			dp[i+1][j+1][3]%=mod;
			
			dp[i+1][j][2]+=dp[i][j][2];
			dp[i+1][j][0]+=dp[i][j][2];
			dp[i+1][j][1]+=dp[i][j][2];
			dp[i+1][j+2][3]+=dp[i][j][2];

			dp[i+1][j][2]%=mod;
			dp[i+1][j][0]%=mod;
			dp[i+1][j][1]%=mod;
			dp[i+1][j+2][3]%=mod;

			dp[i+1][j][3]+=dp[i][j][3];
			dp[i+1][j][0]+=dp[i][j][3];
			dp[i+1][j][1]+=dp[i][j][3];
			dp[i+1][j+2][2]+=dp[i][j][3];

			dp[i+1][j][3]%=mod;
			dp[i+1][j][0]%=mod;
			dp[i+1][j][1]%=mod;
			dp[i+1][j+2][2]%=mod;
		}
	}
	cout<<(dp[n][z][0]+dp[n][z][1]+dp[n][z][2]+dp[n][z][3])%mod<<endl;
	return 0;
}