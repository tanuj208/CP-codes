#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

ll mod=1000000007;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,k,i;
	cin>>t>>k;
	ll dp[100005];
	dp[0]=0;
	for(i=1;i<k;i++)
		dp[i]=1;
	dp[k]=2;
	for(i=k+1;i<=100000;i++)
		dp[i]=(dp[i-1]+dp[i-k])%mod;
	for(i=1;i<=100000;i++)
		dp[i]=dp[i]+dp[i-1];
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1])%mod<<endl;
	}
	return 0;
}