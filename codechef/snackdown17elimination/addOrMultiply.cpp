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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a;
		ll i;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		if(n==1)
		{
			cout<<a[0]<<"\n";
			continue;
		}
		vector<ll> dp(100005, 0);
		dp[n-1]=a[n-1]%mod;
		dp[n-2]=((a[n-1]*a[n-2])%mod+a[n-1]+a[n-2])%mod;
		ll fac=2;
		ll expr=(a[n-1]+(a[n-1]*a[n-2])%mod)%mod;
		for(i=n-3;i>=0;i--)
		{
			dp[i]=(2*dp[i+1])%mod;
			dp[i]+=(fac*a[i])%mod;
			dp[i]%=mod;
			dp[i]+=(expr*(a[i]-1))%mod;
			expr*=a[i];
			expr%=mod;
			expr+=(a[i]*fac)%mod;
			expr%=mod;
			fac*=2;
			fac%=mod;
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}