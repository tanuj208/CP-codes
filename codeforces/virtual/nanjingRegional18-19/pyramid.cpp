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

ll sum(ll x)
{
	ll ans=x*(x+1);
	ans/=2;
	ans%=mod;
	return ans;
}

ll sum2(ll x)
{
	ll ans=(x*(x+1))%mod;
	ans=(ans*(2*x+1))%mod;
	ans=(ans*power(6,mod-2))%mod;
	return ans;
}

ll sum3(ll x)
{
	ll ans=x*(x+1);
	ans/=2;
	ans%=mod;
	ans*=ans;
	ans%=mod;
	return ans;
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
		ll k=n/3;

		ll tmpp=(n%8)*((n+2)%8)*((2*n+1)%8);
		tmpp%=8;


		ll ans=n*(n+2);
		ans%=mod;
		ans*=(2*n+1);
		ans%=mod;
		ans-=tmpp;
		ans+=mod;
		ans%=mod;
		ans*=power(8, mod-2);
		ans%=mod;

		ll ans2=0;

		ll tmp2=n;
		tmp2*=n;
		tmp2%=mod;

		ll a=(tmp2+3*n+2)%mod;
		a*=k;
		a%=mod;
		ans2+=a;
		ans2%=mod;

		a=(2*n+3)%mod;
		a%=mod;
		a*=3;
		a%=mod;
		a*=sum(k);
		a%=mod;

		ans2-=a;
		ans2+=mod;
		ans2%=mod;

		a=9;
		a*=sum2(k);
		a%=mod;

		ans2+=a;
		ans2%=mod;

		ans2*=power(2, mod-2);
		ans2%=mod;

		ans+=2*ans2;
		ans%=mod;

		cout<<ans<<endl;
	}
	return 0;
}