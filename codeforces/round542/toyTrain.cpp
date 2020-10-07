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

ll n,m;

ll dist(ll i,ll j)
{
	if(j<i)
		j+=n;
	return j-i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	pii can[5005];
	ll i;
	for(i=1;i<=n;i++)
		can[i]=mp(LLONG_MAX,0);
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(b<a)
			b+=n;
		can[a].ss++;
		can[a].ff = min(can[a].ff, b-a);
	}
	vector<ll> ans;
	for(i=1;i<=n;i++)
	{
		ans.pb(0);
		ll j;
		for(j=1;j<=n;j++)
		{
			if(can[j].ss==0)
				continue;
			ll val=dist(i,j);
			val+=n*(can[j].ss-1);
			val+=can[j].ff;
			ans[i-1]=max(ans[i-1], val);
		}
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}