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
	ll z;
	ll t;
	ll i;
	cin>>t;
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n;
		cin>>n;
		string s;
		cin>>s;
		vector<ll> cum;
		cum.pb(0);
		cum.pb(s[0]-'0');
		for(i=1;i<n;i++)
			cum.pb(cum[i]+s[i]-'0');
		ll ans=0;
		for(i=1;i<=n;i++)
		{
			ll tmp=(i+1)/2;
			ll x=cum[i]-cum[i-tmp];
			if(i%2==1)
				x+=cum[(n+i)/2]-cum[i];
			else
				x+=cum[(n+i+1)/2]-cum[i];
			if((n-i)%2==1 && n%2==1)
			{
				ll tmpp=min(cum[(n+i+1)/2]-cum[i/2], cum[(n+i)/2]-cum[(i-2)/2]);
				ans=max(ans,tmpp);
			}
			else
				ans=max(ans,x);
		}
		cout<<ans<<"\n";
	}
	return 0;
}