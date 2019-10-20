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
			char c;
			cin>>c;
			if(c=='#')
				a.pb(1);
			else
				a.pb(-1);
		}
		vector<ll> b(n+1, -1);
		vector<ll> dp;
		ll var=0;
		i=0;
		while(a[i]==1 && i<n)
		{
			dp.pb(0);
			b[i]=1;
			i++;
		}
		for(;i<n;i++)
		{
			var+=a[i];
			var=max(var,(ll)0);
			dp.pb(var);
		}
		if(var!=0)
		{
			cout<<"-1\n";
			continue;
		}
		ll ans=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==-1 || dp[i]==0)
				continue;
			ans+=(dp[i]-1);
			b[i+dp[i]-1]=1;
		}
		// for(i=0;i<n;i++)
			// cout<<b[i]<<" ";
		// cout<<endl;
		// cout<<ans<<endl;
		ll cntr=0;
		for(i=0;i<n;i++)
		{
			if(b[i]==1)
			{
				ans+=(i-cntr);
				cntr++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}