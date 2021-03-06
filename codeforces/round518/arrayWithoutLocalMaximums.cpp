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

ll mod=998244353;

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

ll dp[100005][205][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i,j;
	for(i=0;i<=100000;i++)
		for(j=1;j<=200;j++)
			dp[i][j][0]=0,dp[i][j][1]=0;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	if(a[0]==-1)
		for(i=1;i<=200;i++)
			dp[0][i][0]++;
	else
		dp[0][a[0]][0]++;

	for(i=1;i<n;i++)
	{
		vector<ll> tmp(205,0);
		if(a[i]==-1)
		{
			for(j=1;j<=200;j++)
				dp[i][j][0]=(dp[i][j-1][0]+dp[i-1][j-1][0])%mod;
			for(j=1;j<=200;j++)
				dp[i][j][1]=dp[i-1][j][0];
			tmp[1]=dp[i-1][1][1];
			for(j=2;j<=200;j++)
				tmp[j]=(tmp[j-1]+dp[i-1][j][1])%mod;
			for(j=2;j<=200;j++)
				dp[i][j][0]=(dp[i][j][0]+tmp[j-1])%mod;
			for(j=1;j<=200;j++)
				tmp[j]=0;
			tmp[200]=dp[i-1][200][1];
			for(j=199;j>=1;j--)
				tmp[j]=(tmp[j+1]+dp[i-1][j][1])%mod;
			for(j=1;j<=200;j++)
				dp[i][j][1]=(dp[i][j][1]+tmp[j])%mod;
		}
		else
		{
			for(j=1;j<a[i];j++)
				dp[i][a[i]][0]=(dp[i][a[i]][0]+dp[i-1][j][0]+dp[i-1][j][1])%mod;
			dp[i][a[i]][1]=(dp[i-1][a[i]][0]+dp[i-1][a[i]][1])%mod;
			for(j=a[i]+1;j<=200;j++)
				dp[i][a[i]][1]=(dp[i][a[i]][1]+dp[i-1][j][1])%mod;
		}
	}
	ll ans=0;
	for(i=1;i<=200;i++)
	{
		ans=(ans+dp[n-1][i][1])%mod;
	}
	cout<<ans<<endl;
	return 0;
}