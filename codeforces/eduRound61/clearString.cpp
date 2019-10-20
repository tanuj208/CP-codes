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

ll dp[505][505];
string t;

void rec(ll i,ll j)
{
	if(i>j)
		return;
	if(dp[i][j]!=-1)
		return;
	rec(i+1,j);
	ll x;
	dp[i][j]=1+dp[i+1][j];
	for(x=i+1;x<=j;x++)
	{
		if(t[x]==t[i])
		{
			rec(i+1,x-1);
			rec(x,j);
			dp[i][j]=min(dp[i][j], dp[i+1][x-1]+dp[x][j]);			
		}
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
	string s;
	cin>>s;
	ll i,j=0;
	for(i=0;i<sz(s);i++)
	{
		if(i==0 || s[i]!=s[i-1])
		{
			t+=s[i];
			j++;
		}
	}
	n=j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=-1;

	for(i=0;i<n;i++)
		dp[i][i]=1;
	for(i=1;i<n;i++)
		dp[i-1][i]=2;
	rec(0,n-1);
	cout<<dp[0][n-1]<<endl;
	return 0;
}