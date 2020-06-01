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
	ll n;
	cin>>n;
	vector<ll> a;
	vector<ll> dp1(n+5, 0);
	vector<ll> dp2(n+5, 0);
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	dp1[0]=1;
	dp2[0]=1;
	ll ans=1;
	for(i=1;i<n;i++)
	{
		// cout<<dp1[i-1]<<"D"<<dp2[i-1].ff<<" "<<dp2[i-1].ss<<endl;
		if(a[i]>a[i-1])
		{
			dp1[i]=1+dp1[i-1];
			dp2[i]=1+dp2[i-1];
		}
		else
		{
			dp1[i]=1;
			if(i!=1 && a[i]>a[i-2])
				dp2[i]=dp1[i-1];
			else
				dp2[i]=1;
		}
		ans=max(ans, dp1[i]);
		ans=max(ans, dp2[i]);
	}
	cout<<ans<<endl;
	return 0;
}