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
	ll n;
	cin>>n;
	vector<ll> a;
	vector<ll> ans(200005);
	a.pb(0);
	ll i;
	for(i=0;i<n/2;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	ans[1]=0;
	ans[n]=a[1];
	for(i=2;i<=n/2;i++)
	{
		if((a[i]-ans[i-1])<=ans[n+2-i])
		{
			ans[i]=ans[i-1];
			ans[n+1-i]=a[i]-ans[i];
		}
		else
		{
			ans[n+1-i]=ans[n+2-i];
			ans[i]=a[i]-ans[n+1-i];
		}
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}