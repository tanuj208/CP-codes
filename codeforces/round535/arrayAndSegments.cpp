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
	ll n,m;
	cin>>n>>m;
	vector<ll> a;
	vector<pii> seg;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r;
		seg.pb(mp(l-1,r-1));
	}
	ll ans=0;
	vector<ll> ansArr;
	for(i=0;i<n;i++)
	{
		ll x=a[i];
		vector<ll> tmp=a;
		vector<ll> tmp2;
		for(ll j=0;j<m;j++)
		{
			if(seg[j].ff > i || seg[j].ss < i)
			{
				for(ll k=seg[j].ff;k<=seg[j].ss;k++)
					tmp[k]--;
				tmp2.pb(j+1);
			}
		}
		ll mn=LLONG_MAX;
		for(ll j=0;j<n;j++)
			mn=min(mn,tmp[j]);
		if(ans<abs(x-mn))
		{
			ans=abs(x-mn);
			ansArr=tmp2;
		}
	}
	cout<<ans<<endl<<sz(ansArr)<<endl;
	for(i=0;i<sz(ansArr);i++)
		cout<<ansArr[i]<<" ";
	cout<<endl;
	return 0;
}