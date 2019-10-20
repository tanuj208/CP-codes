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

ll marked[1005][1005];
ll wt[1005][1005];
vector<ll> ans[1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			marked[i][j]=0;
	for(i=0;i<2*m;i++)
	{
		ll x,y;
		cin>>x>>y;
		marked[x][y]=1;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>wt[i][j];
	ll cur=0;
	bool flag=false;
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(j=1;j<=n;j++)
			{
				if(flag)
				{
					ans[cur].pb(i);
					ans[cur].pb(j);
				}
				if(marked[i][j]==1)
				{
					if(flag)
						cur++;
					else
					{
						ans[cur].pb(i);
						ans[cur].pb(j);
					}
					flag=!flag;
				}
			}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				if(flag)
				{
					ans[cur].pb(i);
					ans[cur].pb(j);
				}
				if(marked[i][j]==1)
				{
					if(flag)
						cur++;
					else
					{
						ans[cur].pb(i);
						ans[cur].pb(j);
					}
					flag=!flag;
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		cout<<sz(ans[i])/2<<" ";
		for(j=0;j<sz(ans[i]);j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}