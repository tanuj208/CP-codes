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
	ll n,t;
	cin>>n>>t;
	ll gr[155][155];
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>gr[i][j];
	pair<ll,pii> dp[155][155];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=mp(1e15, mp(-1, -1));
	dp[0][0]=mp(0,mp(1,1));
	ll k;
	for(k=0;k<n+1;k++)
	{
		pair<ll,pii> tmp[155][155];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				ll an=dp[i][j].ff;
				ll r=dp[i][j].ss.ff;
				ll c=dp[i][j].ss.ss;
				ll mxr=-1,mxc=-1;
				if(i!=0)
				{
					if(an >= dp[i-1][j].ff+gr[i][j])
					{
						an=dp[i-1][j].ff+gr[i][j];
						ll rr=dp[i-1][j].ss.ff;
						ll cc=dp[i-1][j].ss.ss;
						mxr=max(rr, r);
						mxc=max(cc, c);
					}
				}
				if(j!=0)
				{
					if(i==0 && j==1)
						cout<<dp[i][j-1].ff+gr[i][j]<<endl;
					if(an >= dp[i][j-1].ff+gr[i][j])
					{
						an=dp[i][j-1].ff+gr[i][j];
						ll rr=dp[i][j-1].ss.ff;
						ll cc=dp[i][j-1].ss.ss;
						mxr=max(rr, r);
						mxc=max(cc, c);
					}
				}
				if(i!=n-1)
				{
					if(an >= dp[i+1][j].ff+gr[i][j])
					{
						an=dp[i+1][j].ff+gr[i][j];
						ll rr=dp[i+1][j].ss.ff;
						ll cc=dp[i+1][j].ss.ss;
						mxr=max(rr, r);
						mxc=max(cc, c);
					}
				}
				if(j!=n-1)
				{
					if(an >= dp[i][j+1].ff+gr[i][j])
					{
						an=dp[i][j+1].ff+gr[i][j];
						ll rr=dp[i][j+1].ss.ff;
						ll cc=dp[i][j+1].ss.ss;
						mxr=max(rr, r);
						mxc=max(cc, c);
					}
				}
				cout<<mxr<<" "<<mxc<<endl;
				tmp[i][j]=mp(an, mp(mxr, mxc));
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				dp[i][j]=tmp[i][j];
	}
	ll ans=1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(dp[i][j].ff<t)
				ans=max(ans, dp[i][j].ss.ff*dp[i][j].ss.ss);
	cout<<ans<<endl;
	return 0;
}