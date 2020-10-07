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
	ll T;
	cin>>T;
	vector<ll> ans(100005);
	while(T--)
	{
		ll n;
		cin>>n;
		vector<pair<pii,ll> > seg;
		ll i;
		for(i=0;i<n;i++)
		{
			ll l,r;
			cin>>l>>r;
			seg.pb(mp(mp(l,r),i));
		}
		sort(seg.begin(),seg.end());
		ll curl=seg[0].ff.ff;
		ll curr=seg[0].ff.ss;
		ans[seg[0].ss]=1;
		bool flag=true;
		for(i=1;i<n;i++)
		{
			ll l=seg[i].ff.ff;
			ll r=seg[i].ff.ss;
			ll ind=seg[i].ss;
			if(l>curr)
			{
				flag=false;
				break;
			}
			ans[ind]=1;
			curr=max(curr,r);
		}
		if(flag)
		{
			cout<<-1<<endl;
			continue;
		}
		for(;i<n;i++)
		{
			ll ind=seg[i].ss;
			ans[ind]=2;
		}
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}