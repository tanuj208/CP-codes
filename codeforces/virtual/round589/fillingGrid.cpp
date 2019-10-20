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
vector<vector<ll>> grid(1005, vector<ll> (1005, -1));

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll h,w;
	cin>>h>>w;
	ll i,j;
	for(i=0;i<h;i++)
	{
		ll val;
		cin>>val;
		for(j=0;j<val;j++)
			grid[i][j]=1;
		if(val!=w)
			grid[i][val]=0;
	}
	for(i=0;i<w;i++)
	{
		ll val;
		cin>>val;
		for(j=0;j<val;j++)
		{
			if(grid[j][i]==0)
			{
				cout<<0<<endl;
				return 0;
			}
			grid[j][i]=1;
		}
		if(val!=h)
		{
			if(grid[val][i]==1)
			{
				cout<<0<<endl;
				return 0;
			}
			grid[val][i]=0;
		}
	}
	ll ans=1;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(grid[i][j]==-1)
				ans = (2*ans)%mod;
	cout<<ans<<endl;
	return 0;
}