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

ll dp[1000][1000];

void rec(ll i,ll j)
{
	if(dp[i][j] != LLONG_MAX)
		return;
	if(j-i<=1)
	{
		dp[i][j]=0;
		return;
	}
	if(j-i==2)
	{
		dp[i][j]=i*(i+1)*(i+2);
		return;
	}
	ll x;
	for(x=i+1;x<=j-1;x++)
	{
		rec(i,x);
		rec(x,j);
		dp[i][j]=min(dp[i][j], i*x*j + dp[i][x] + dp[x][j]);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i,j;
	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			dp[i][j]=LLONG_MAX;
	rec(1,n);
	cout<<dp[1][n]<<endl;
	return 0;
}