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
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n,k,p;
		cin>>n>>k>>p;
		vector<vector<ll>> st;
		ll i,j;
		for(i=0;i<n;i++)
		{
			vector<ll> tmp;
			for(j=0;j<k;j++)
			{
				ll val;
				cin>>val;
				tmp.pb(val);
			}
			st.pb(tmp);
		}
		vector<vector<ll>> dp(n+5, vector<ll> (p+5, 0)); // pick j plates from i stacks;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=p;j++)
				dp[i][j] = dp[i-1][j];
			ll cur_sum = 0;
			for(j=0;j<k;j++)
			{
				cur_sum += st[i-1][j];
				for(ll x=0;x<p;x++)
				{
					ll cur_pl = x+j+1;
					if(cur_pl > p)
						break;
					dp[i][cur_pl] = max(dp[i][cur_pl], dp[i-1][x]+cur_sum);
				}
			}
		}
		cout<<dp[n][p]<<endl;
	}
	return 0;
}