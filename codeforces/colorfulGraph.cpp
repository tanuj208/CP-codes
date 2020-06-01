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

// priority_queue <ll,vector<ll>,greater<ll> > p;

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
	ll n,m;
	cin>>n>>m;
	ll i;
	vector<ll> col;
	vector<ll> ad[100005];
	ll minCol=LLONG_MAX;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		col.pb(val);
		minCol=min(minCol, val);
	}
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ll col1=col[u-1];
		ll col2=col[v-1];
		if(col1!=col2)
		{
			ad[col1].pb(col2);
			ad[col2].pb(col1);
		}
	}
	for(i=1;i<=100000;i++)
		sort(all(ad[i]));
	ll mxDeg=0;
	ll ans=0;
	for(i=1;i<=100000;i++)
	{
		ll cur=0;
		for(ll j=0;j<sz(ad[i]);j++)
		{
			if(j==0 || ad[i][j] != ad[i][j-1])
				cur++;
		}
		if(mxDeg<cur)
		{
			mxDeg=cur;
			ans=i;
		}
	}
	if(ans==0)
		cout<<minCol<<endl;
	else
		cout<<ans<<endl;
	return 0;
}