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
vector<pii> a;
ll n;

void func(ll i,ll j)
{
	if(dp[i][j]!=-1)
		return;
	if(i==j)
	{
		dp[i][j]=0;
		return;
	}
	func(i,j-1);
	func(i+1,j);
	dp[i][j]=max(dp[i][j-1], max(dp[i+1][j], (a[i].ff - a[j].ff) * (a[i].ff - a[j].ff) + (a[i].ss - a[j].ss) * (a[i].ss - a[j].ss)));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,j;
	for(i=0;i<=3000;i++)
		for(j=0;j<=3000;j++)
			dp[i][j]=-1;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	for(i=0;i<=3000;i++)
		for(j=0;j<=3000;j++)
			func(i,j);
	ll q;
	cin>>q;
	while(q--)
	{
		ll f,t;
		cin>>f>>t;
		cout<<dp[f-1][t-1]<<endl;
	}
	return 0;
}