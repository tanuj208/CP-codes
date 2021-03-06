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

vector<ll> a(100005),b(100005),c(100005);
ll dp[100005][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	dp[1][0]=a[1];
	dp[1][1]=b[1];
	dp[1][2]=c[1];
	for(i=2;i<=n;i++)
	{
		dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
	return 0;
}