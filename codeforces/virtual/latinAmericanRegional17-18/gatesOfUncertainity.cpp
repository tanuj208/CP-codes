#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

vector<ll> ad[100005];
vector<ll> st(100005);
ll dp[100005][4];  // 0 tc 1 ti 2 fc 3 fi

void dfs(ll v)
{
	if(dp[v][0]!=-1)
		return;
	ll i;
	
	dp[v][0]=0,dp[v][1]=0,dp[v][2]=0,dp[v][3]=0;

	if(sz(ad[v])==1)
	{
		ll x=ad[v][0];

		dfs(x);

		dp[v][2]+=dp[x][0];
		dp[v][2]%=mod;

		dp[v][3]+=dp[x][1];
		dp[v][3]%=mod;

		dp[v][1]+=dp[x][3];
		dp[v][1]%=mod;

		dp[v][0]+=(dp[x][0]+dp[x][1]+dp[x][3]+2*dp[x][2])%mod;
	}
	else if(sz(ad[v])==0)
	{
		dp[v][0]=3;
		dp[v][2]=1;
	}
	else
	{
		ll x=ad[v][0];
		ll y=ad[v][1];

		dfs(x);
		dfs(y);

		ll tmp=(dp[x][0]*dp[y][0])%mod;
		dp[v][2]+=tmp;
		dp[v][2]%=mod;

		tmp=(dp[x][0]*dp[y][1])%mod;
		dp[v][3]+=tmp;
		dp[v][3]%=mod;

		tmp=(dp[x][0]*dp[y][2])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][0]*dp[y][3])%mod;
		dp[v][1]+=tmp;
		dp[v][1]%=mod;

		tmp=(dp[x][1]*dp[y][0])%mod;
		dp[v][3]+=tmp;
		dp[v][3]%=mod;

		tmp=(dp[x][1]*dp[y][1])%mod;
		dp[v][3]+=tmp;
		dp[v][3]%=mod;

		tmp=(dp[x][1]*dp[y][2])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][1]*dp[y][3])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][2]*dp[y][0])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][2]*dp[y][1])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][2]*dp[y][2])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][2]*dp[y][3])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][3]*dp[y][0])%mod;
		dp[v][1]+=tmp;
		dp[v][1]%=mod;

		tmp=(dp[x][3]*dp[y][1])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][3]*dp[y][2])%mod;
		dp[v][0]+=tmp;
		dp[v][0]%=mod;

		tmp=(dp[x][3]*dp[y][3])%mod;
		dp[v][1]+=tmp;
		dp[v][1]%=mod;
	}


	if(st[v]==1)
	{
		dp[v][0]+=dp[v][3];
		dp[v][0]%=mod;

		dp[v][1]+=dp[v][2];
		dp[v][1]%=mod;

		dp[v][2]=0;
		dp[v][3]=0;
		return;
	}

	if(st[v]==0)
	{
		dp[v][2]+=dp[v][1];
		dp[v][2]%=mod;

		dp[v][3]+=dp[v][0];
		dp[v][3]%=mod;

		dp[v][1]=0;
		dp[v][0]=0;
		return;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	memset(dp, -1, sizeof(dp));
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ll x,y,f;
		cin>>x>>y>>f;
		if(x!=0)
			ad[i].pb(x);
		if(y!=0)
			ad[i].pb(y);
		st[i]=f;
	}

	dfs(1);
	// cout<<dp[3][3]<<endl;
	cout<<(dp[1][1]+dp[1][3])%mod<<endl;
	return 0;
}