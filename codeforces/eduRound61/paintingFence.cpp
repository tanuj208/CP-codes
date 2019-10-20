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
	ll n,q;
	cin>>n>>q;
	vector<pii> x;
	vector<ll> p(5005,0);
	ll i;
	for(i=0;i<q;i++)
	{
		ll l,r;
		cin>>l>>r;
		ll j;
		for(j=l;j<=r;j++)
			p[j]++;
		x.pb(mp(l,r));
	}
	ll cont = LLONG_MAX;
	ll rem;
	for(i=0;i<q;i++)
	{
		ll s=0;
		ll l=x[i].ff;
		ll r=x[i].ss;
		ll j;
		for(j=l;j<=r;j++)
			if(p[j]==1)
				s++;
		if(cont>s)
		{
			cont=s;
			rem=i;
		}
	}
	ll j;
	for(j=x[rem].ff;j<=x[rem].ss;j++)
		p[j]--;
	x.erase(x.begin()+rem);
	cont = LLONG_MAX;
	for(i=0;i<q-1;i++)
	{
		ll s=0;
		ll l=x[i].ff;
		ll r=x[i].ss;
		ll j;
		for(j=l;j<=r;j++)
			if(p[j]==1)
				s++;
		if(cont>s)
		{
			cont=s;
			rem=i;
		}
	}
	for(j=x[rem].ff;j<=x[rem].ss;j++)
		p[j]--;
	ll ans=0;
	for(i=1;i<=n;i++)
		if(p[i]!=0)
			ans++;
	cout<<ans<<endl;
	return 0;
}