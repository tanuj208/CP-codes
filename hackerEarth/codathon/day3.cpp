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
	ll n,m,l;
	cin>>n>>m>>l;
	ll i;
	vector<ll> types(m+5,0);
	for(i=0;i<l;i++)
	{
		ll val;
		cin>>val;
		val%=m;
		types[val]++;
	}
	// for(i=0;i<m;i++)
	// 	cout<<types[i]<<" ";
	// cout<<endl;
	vector<ll> dp(m+5,0);
	vector<ll> dp2(m+5,0);
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		ll j;
		for(j=0;j<m;j++)
		{
			ll k;
			for(k=0;k<m;k++)
			{
				ll new_mod=(k+j)%m;
				dp2[new_mod]+=(types[k]*dp[j])%mod;
				dp2[new_mod]%=mod;
				// cout<<new_mod<<" "<<dp[new_mod]<<endl;
			}
		}
		dp=dp2;
		for(j=0;j<m;j++)
			cout<<dp[j]<<" ";
		cout<<endl;
	}
	cout<<dp[0]<<endl;
	return 0;
}