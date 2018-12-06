#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll dp[705][705][2];

void func(ll l, ll r)
{
	ll i;
	if(dp[l+1][r][0]==-1)
		func(l+1,r)
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i,val,j,k;
	for(i=0;i<=700;i++)
		for(j=0;j<=700;j++)
			dp[i][j][0]=-1,dp[i][j][1]=-1;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	return 0;
}