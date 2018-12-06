#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll c[100004]={0},f[100004]={0},h[13];
	ll i,j,x,val;
	for(i=0;i<n*k;i++)
	{
		cin>>val;
		c[val]++;
	}
	for(i=1;i<=n;i++)
	{
		cin>>val;
		f[val]++;
	}
	for(i=1;i<=k;i++)
		cin>>h[i];
	h[0]=0;
	ll dp[503][5044]={0};
	for(i=0;i<=500;i++)
		for(j=0;j<=5000;j++)
			for(x=0;x<=k;x++)
				dp[i+1][j+x]=max(dp[i+1][j+x],dp[i][j]+h[x]);
	ll ans=0;
	for(i=1;i<=100000;i++)
		ans+=dp[f[i]][c[i]];
	cout<<ans<<endl;
	return 0;
}