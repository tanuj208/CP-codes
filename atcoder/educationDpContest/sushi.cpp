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

double dp[305][305][305];
ll n;

void rec(ll a1,ll b1,ll c1)
{
	if(dp[a1][b1][c1]!=-1)
		return;
	double x1,x2,x3;
	if(a1>0)
	{
		rec(a1-1,b1,c1);
		x1=dp[a1-1][b1][c1]+1;
	}
	else
		x1=0;
	if(b1>0)
	{
		rec(a1+1,b1-1,c1);
		x2=dp[a1+1][b1-1][c1]+1;
	}
	else
		x2=0;
	if(c1>0)
	{
		rec(a1,b1+1,c1-1);
		x3=dp[a1][b1+1][c1-1]+1;
	}
	else
		x3=0;
	double x=a1*x1+b1*x2+c1*x3;
	double xx=a1+b1+c1;
	x+=n;
	x/=xx;
	// if(a1==1)
	// {
	// 	cout<<x<<" "<<xx<<endl;
	// }
	x--;
	dp[a1][b1][c1]=x;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vector<ll> a;
	ll i,j,k;
	for(i=0;i<=300;i++)
		for(j=0;j<=300;j++)
			for(k=0;k<=300;k++)
				dp[i][j][k]=-1;
	ll a1=0,b1=0,c1=0;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		if(val==1)
			a1++;
		else if(val==2)
			b1++;
		else
			c1++;
	}
	dp[0][0][0]=0;
	rec(a1,b1,c1);
	// cout<<dp[1][0][0]<<endl;
	printf("%.13lf\n", dp[a1][b1][c1]);
	return 0;
}