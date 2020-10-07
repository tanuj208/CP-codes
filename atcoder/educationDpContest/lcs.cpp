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

ll dp[3005][3005];
string ans;
string a,b;

void rec(ll i,ll j)
{
	if(dp[i][j]!=-1)
		return;
	if(a[i]==b[j])
	{
		rec(i-1,j-1);
		dp[i][j]=dp[i-1][j-1]+1;
		return;
	}
	rec(i-1,j);
	rec(i,j-1);
	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	return;
}

void rec2(ll i,ll j)
{
	if(i<0 || j<0)
		return;
	if(a[i]==b[j])
	{
		ans+=a[i];
		rec2(i-1,j-1);
		return;
	}
	if(i==0 && j==0)
		return;
	if(i!=0 && j==0)
	{
		rec2(i-1,j);
		return;
	}
	else if(j!=0 && i==0)
	{
		rec2(i,j-1);
		return;
	}
	if(dp[i-1][j]>=dp[i][j-1])
		rec2(i-1,j);
	else
		rec2(i,j-1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	ll i,j;
	ll n=sz(a);
	ll m=sz(b);
	for(i=0;i<=3000;i++)
		for(j=0;j<=3000;j++)
			dp[i][j]=-1;
	if(a[0]!=b[0])
		dp[0][0]=0;
	else
		dp[0][0]=1;
	for(i=1;i<n;i++)
		if(a[i]==b[0] || dp[i-1][0]==1)
			dp[i][0]=1;
	for(i=1;i<m;i++)
		if(b[i]==a[0] || dp[0][i-1]==1)
			dp[0][i]=1;
	rec(n-1,m-1);
	rec2(n-1,m-1);
	reverse(all(ans));
	cout<<ans<<endl;
	// cout<<dp[1][3]<<endl;

	return 0;
}