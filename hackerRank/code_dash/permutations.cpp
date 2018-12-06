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
	ll n,k;
	cin>>n>>k;
	vector<pii> a;
	ll i;
	for(i=0;i<k;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	sort(a.begin(),a.end());
	vector<ll> fac(1000005,0);
	fac[0]=1;
	for(i=1;i<=1000000;i++)
		fac[i]=(fac[i-1]*i)%mod;
	ll ans;
	ll num=fac[n];
	ll den=1;
	for(i=0;i<k;i++)
	{
		den=(den*power(fac[a[i].first], a[i].second))%mod;
		den=(den*fac[a[i].second])%mod;
		num=(num*power(fac[a[i].first-1], a[i].second))%mod;
	}
	ans=(num*power(den,mod-2))%mod;
	cout<<ans<<endl;
	return 0;
}