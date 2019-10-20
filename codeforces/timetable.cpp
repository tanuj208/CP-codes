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
	ll n,m,k;
	cin>>n>>m>>k;
	vector<string> x;
	ll i,j;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		x.pb(s);
	}
	ll nn;
	ll dp[505][505],mn[505][505];
	for(i=0;i<=500;i++)
		for(j=0;j<=500;j++)
			dp[i][j]=LLONG_MAX;
	ll lessons[505]={0};
	ll total=0;
	for(i=0;i<=500;i++)
		for(j=0;j<=500;j++)
			mn[i][j]=LLONG_MAX,dp[i][j]=LLONG_MAX;
	for(i=0;i<n;i++)
	{
		mn[i][0]=0;
		mn[i][1]=1;
		for(j=0;j<m;j++)
		{
			if(x[i][j]=='1')
			{
				lessons[i]++;
				ll xx=1;
				for(nn=j+1;nn<m;nn++)
				{
					if(x[i][nn]=='1')
					{
						xx++;
						mn[i][xx]=min(mn[i][xx],nn-j+1);
					}
				}
			}
		}
		total+=lessons[i];
	}
	if(total<=k)
	{
		cout<<"0\n";
		return 0;
	}
	for(j=0;j<=lessons[0];j++)
		dp[0][j]=mn[0][lessons[0]-j];
	ll canmiss=0;
	for(i=0;i<n-1;i++)
	{
		canmiss+=lessons[i];
		for(j=0;j<=canmiss;j++)
		{
			for(nn=0;nn<=k-j && nn<=lessons[i+1];nn++)
				dp[i+1][j+nn]=min(dp[i][j]+mn[i+1][lessons[i+1]-nn],dp[i+1][j+nn]);
		}
	}
	cout<<dp[n-1][k]<<endl;
	return 0;
}