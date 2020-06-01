#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll m,n;
	cin>>m>>n;
	ll dp[m+2][n+2][2]={0};
	ll i,j,k;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<2;k++)
				dp[i][j][k]=0;
	for(i=0;i<n;i++)
	{
		if(i%2==1)
			dp[0][i][0]=1;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<2;k++)
			{
				ll oth;
				if(k==0)
					oth=1;
				else
					oth=0;
				if(i+2 < m)
				{
					if(j+1 < n)
					{
						dp[i+2][j+1][oth]+=dp[i][j][k];
						dp[i+2][j+1][oth]%=mod;
					}
					if(j-1 >= 0)
					{
						dp[i+2][j-1][oth]+=dp[i][j][k];
						dp[i+2][j-1][oth]%=mod;
					}
				}
				if(i+1 < m)
				{
					if(j+2 < n)
					{
						dp[i+1][j+2][oth]+=dp[i][j][k];
						dp[i+1][j+2][oth]%=mod;
					}
					if(j-2 >= 0)
					{
						dp[i+1][j-2][oth]+=dp[i][j][k];
						dp[i+1][j-2][oth]%=mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ans+=dp[m-1][i][1];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}