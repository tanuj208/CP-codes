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

vector<ll> dp(800000,0);
vector<ll> divisors[800000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll i,j;
	for(i=1;i<=750000;i++)
		for(j=2*i;j<=750000;j+=i)
			divisors[j].pb(i);

	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		for(i=0;i<=750000;i++)
			dp[i]=0;
		sort(a.begin(),a.end());
		dp[a[0]]++;
		for(i=1;i<n;i++)
		{
			ll x=a[i];
			dp[x]++;
			for(j=0;j<sz(divisors[x]);j++)
				dp[x]=(dp[x]+dp[divisors[x][j]])%mod;
		}
		ll ans=0;
		for(i=1;i<=750000;i++)
			ans=(ans+dp[i])%mod;
		cout<<ans<<"\n";
	}
	return 0;
}