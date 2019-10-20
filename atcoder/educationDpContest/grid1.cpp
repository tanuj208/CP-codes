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

ll dp[1005][1005];
ll h,w;
ll mat[1005][1005];

ll rec(ll i,ll j)
{
	if(i>=h || j>=w)
		return 0;
	if(i<0 || j<0)
		return 0;
	if(mat[i][j]==1)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=(rec(i-1,j)+rec(i,j-1))%mod;
	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>h>>w;
	ll i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			dp[i][j]=-1;
	dp[0][0]=1;
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			char c;
			cin>>c;
			if(c=='.')
				mat[i][j]=0;
			else
				mat[i][j]=1;
		}
	}
	cout<<rec(h-1,w-1)<<endl;
	return 0;
}