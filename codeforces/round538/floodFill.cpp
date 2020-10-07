#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
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
typedef pair<int,int> pii;

int mod=1000000007;

int power(int x, int y) 
{
	int temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int dp[5005][5005][2]={0};  // 0 for left and 1 for right
vector<int> c;

int outputAns(int i,int j)
{
	return min(dp[i][j][0],dp[i][j][1]);
}

void rec(int i,int j)
{
	if(i>j)
		return;
	if(dp[i][j][0]!=-1)
		return;
	if((j-i)==1)
	{
		if(c[i]==c[j])
			dp[i][j][0]=0,dp[i][j][1]=0;
		else
			dp[i][j][0]=1,dp[i][j][1]=1;
		return;
	}
	dp[i][j][0]=INT_MAX;
	dp[i][j][1]=INT_MAX;
	rec(i,j-1);
	rec(i+1,j);
	if(c[j]==c[j-1])
	{
		dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][0]);
		dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]);
	}
	if(c[i]==c[i+1])
	{
		dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]);
		dp[i][j][1]=min(dp[i][j][1],dp[i+1][j][1]);
	}
	if(c[i]==c[j])
	{
		int x1=dp[i+1][j][1];
		int x2=dp[i][j-1][0];
		dp[i][j][0]=min(dp[i][j][0],min(x1,x2));
		dp[i][j][1]=min(dp[i][j][1],min(x1,x2));
	}
	dp[i][j][1]=min(dp[i][j][1], 1+min(dp[i][j-1][0],dp[i][j-1][1]));
	dp[i][j][0]=min(dp[i][j][0], 1+min(dp[i+1][j][0],dp[i+1][j][1]));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int i,j;
	cin>>n;
	c.pb(-1);
	for(i=0;i<n;i++)
	{
		int val;
		cin>>val;
		c.pb(val);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			dp[i][j][0]=-1,dp[i][j][1]=-1;
	for(i=1;i<=n;i++)
		dp[i][i][0]=0,dp[i][i][1]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			rec(i,j);
	cout<<outputAns(1,n)<<endl;
	return 0;
}