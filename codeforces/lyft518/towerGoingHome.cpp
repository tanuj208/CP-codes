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
	vector<ll> v;
	vector<ll> tmp;
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		v.pb(val);
	}
	ll cnt=0;
	for(i=0;i<m;i++)
	{
		ll x1,x2,y;
		cin>>x1>>x2>>y;
		if(x1==1)
		{
			tmp.pb(x2);
			if(x2==1000000000)
				cnt++;
		}
	}
	sort(v.begin(),v.end());
	sort(tmp.begin(),tmp.end());
	m=sz(tmp);
	ll ans=LLONG_MAX;
	for(i=0;i<sz(v);i++)
	{
		ll k=lower_bound(tmp.begin(),tmp.end(),v[i])-tmp.begin();
		ans=min(ans,i+m-k);
	}
	ans=min(ans,n+cnt);
	cout<<ans<<endl;
	return 0;
}