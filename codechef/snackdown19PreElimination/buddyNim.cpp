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
		ll n,m;
		cin>>n>>m;
		ll i;
		ll flag=0;
		vector<ll> a;
		vector<ll> b;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			if(val!=0)
				a.pb(val);
		}
		for(i=0;i<m;i++)
		{
			ll val;
			cin>>val;
			if(val!=0)
				b.pb(val);
		}

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		if(sz(a)!=sz(b))
			flag=1;

		if(sz(a)==sz(b))
			for(i=0;i<sz(a);i++)
				if(a[i]!=b[i])
					flag=1;

		if(flag==0)
			cout<<"Bob\n";
		else
			cout<<"Alice\n";
	}
	return 0;
}