#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll ans=0;
ll n,m,k;
ll a[25][25];
map<ll,ll> dp[25][25];

void func(ll i,ll j,ll x,ll hf,ll mvs)
{
	if(i>=n || j>=m)
		return;
	x=x^a[i][j];
	if(mvs==hf)
	{
		dp[i][j][x]++;
		return;
	}
	func(i+1,j,x,hf,mvs+1);
	func(i,j+1,x,hf,mvs+1);
	return;
}

void funcc(ll i,ll j,ll x,ll hf,ll mvs)
{
	if(i<0 || j<0)
		return;
	if(mvs==hf)
	{
		if(dp[i][j].find(x^k)!=dp[i][j].end())
			ans+=(dp[i][j][x^k]);
		return;
	}
	x=x^a[i][j];
	funcc(i-1,j,x,hf,mvs+1);
	funcc(i,j-1,x,hf,mvs+1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	ll tmp=(n+m-2)/2;
	func(0,0,0,tmp,0);
	funcc(n-1,m-1,0,(n+m-2)-tmp,0);
	cout<<ans<<endl;
	return 0;
}