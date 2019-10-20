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

ll dp[305][305][605];
ll dp2[305][305][605];

void reset()
{
	ll i,j,k;
	for(i=0;i<=300;i++)
		for(j=0;j<=300;j++)
			for(k=0;k<=600;k++)
				dp[i][j][k]=0,dp2[i][j][k]=0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<string> x;
		ll i,j,k;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			x.pb(s);
		}
		reset();
		for(i=1;i<=n+m-2;i++)
			dp[0][0][i]=0,dp2[0][m-1][i]=0;
		for(i=1;i<m;i++)
		{
			if(x[0][i-1]=='1')
				dp[0][i][1]=1;
			for(j=2;j<=n+m-2;j++)
				dp[0][i][j]=dp[0][i-1][j-1];
		}
		for(i=1;i<n;i++)
		{
			if(x[i-1][0]=='1')
				dp[i][0][1]=1;
			for(j=2;j<=n+m-2;j++)
				dp[i][0][j]=dp[i-1][0][j-1];
		}
		for(i=m-2;i>=0;i--)
		{
			if(x[0][i+1]=='1')
				dp2[0][i][1]=1;
			for(j=2;j<=n+m-2;j++)
				dp2[0][i][j]=dp2[0][i+1][j-1];
		}
		for(i=1;i<n;i++)
		{
			if(x[i-1][m-1]=='1')
				dp2[i][m-1][1]=1;
			for(j=2;j<=n+m-2;j++)
				dp2[i][m-1][j]=dp2[i-1][m-1][j-1];
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++)
			{
				ll xx=0;
				if(x[i-1][j]=='1')
					xx++;
				if(x[i][j-1]=='1')
					xx++;
				// if(i==2 && j==2)
				// 	cout<<xx<<endl;
				dp[i][j][1]=xx;
				for(k=2;k<=n+m-2;k++)
					dp[i][j][k]=(dp[i-1][j][k-1]+dp[i][j-1][k-1]-dp[i-1][j-1][k-2]);
				if(x[i-1][j-1]=='1')
					dp[i][j][2]--;
			}
		}
		// cout<<dp[2][2][1]<<endl;
		for(i=1;i<n;i++)
		{
			for(j=m-2;j>=0;j--)
			{
				ll xx=0;
				if(x[i-1][j]=='1')
					xx++;
				if(x[i][j+1]=='1')
					xx++;
				dp2[i][j][1]=xx;
				for(k=2;k<=n+m-2;k++)
					dp2[i][j][k]=(dp2[i-1][j][k-1]+dp2[i][j+1][k-1]-dp2[i-1][j+1][k-2]);
				if(x[i-1][j+1]=='1')
					dp2[i][j][2]--;
			}
		}
		vector<ll> ans(605,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(x[i][j]=='0')
					continue;
				for(k=1;k<=n+m-2;k++)
					ans[k]+=dp[i][j][k]+dp2[i][j][k];
			}
		}

		for(j=0;j<m;j++)
		{
			vector<ll> tmp;
			for(i=0;i<n;i++)
			{
				if(x[i][j]=='1')
					tmp.pb(i);
			}
			for(ll zz=0;zz<sz(tmp);zz++)
				for(ll z=zz+1;z<sz(tmp);z++)
					ans[tmp[z]-tmp[zz]]--;
		}
		for(i=0;i<n;i++)
		{
			vector<ll> tmp;
			for(j=0;j<m;j++)
			{
				if(x[i][j]=='1')
					tmp.pb(j);
			}
			for(ll zz=0;zz<sz(tmp);zz++)
				for(ll z=zz+1;z<sz(tmp);z++)
					ans[tmp[z]-tmp[zz]]--;
		}

		for(i=1;i<=n+m-2;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}