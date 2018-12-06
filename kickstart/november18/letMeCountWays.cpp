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
	ll z,t,i;
	vector<ll> fac;
	fac.pb(1);
	for(i=1;i<=2000005;i++)
		fac.pb((i*fac[i-1])%mod);
	cin>>t;
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n,m;
		cin>>n>>m;
		vector<ll> ncr;
		ncr.pb(1);
		for(i=1;i<=m;i++)
		{
			ll num=((m-i+1)*ncr[i-1])%mod;
			ll den=i;
			ncr.pb((num*power(den,mod-2))%mod);
		}
		ll fact=1;
		ll ans=0;
		for(i=0;i<=m;i++)
		{
			// ll xxx=(fac[n]*((power(fac[i], mod-2))*power(fac[n-i], mod-2))%mod)%mod;
			ll xx=(fac[2*n-i]*((fact*ncr[i])%mod))%mod;
			if(i%2==0)
				ans=(ans+xx)%mod;
			else
				ans=(ans-xx+2*mod)%mod;
			fact=(fact*2)%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}