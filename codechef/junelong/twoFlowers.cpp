#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,m;
ll mat[2003][2003];
map<ll,ll> dp[2003][2003];

void func(ll i,ll j)
{
	if(i>=n || j>=m)
		return;
	if((i==n-1 && j==m-2) || (i==n-2 && j==m-1))
	{
		dp[i][j].insert(mp(mat[n-1][m-1],2));
		return;
	}
	if(i+1<n)
	{
		func(i+1,j);
		ll x=mat[i][j];
		if(mat[i+1][j]==mat[i][j])
		{
			dp[i][j].insert(dp[i+1][j].begin(),dp[i+1][j].end());
			for(auto it=dp[i][j].begin();it!=dp[i][j].end();it++)
				dp[i][j][(*it).first]++;
		}
		else if(dp[i+1][j].find(x)!=dp.end())
			dp[i][j].insert(mp(mat[i+1][j],dp[i+1][j][x]+1));
		else
			dp[i][j].insert(mp(mat[i+1][j],2));
	}
	if(j+1<m)
	{
		func(i,j+1);
		ll x=mat[i][j];
		if(mat[i][j+1]==mat[i][j])
		{
			dp[i][j].insert(dp[i][j+1].begin(),dp[i][j+1].end());
			for(auto it=dp[i][j].begin();it!=dp[i][j].end();it++)
				dp[i][j][(*it).first]++;
		}
		else if(dp[i][j+1].find(x)!=dp.end())
			dp[i][j].insert(mp(mat[i][j+1],dp[i][j+1][x]+1));
		else
			dp[i][j].insert(mp(mat[i][j+1],2));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>mat[i][j];
	return 0;
}