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
	ll n,k;
	cin>>n>>k;
	ll i;
	vector<pii> a;
	map<ll, ll> hsh;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		hsh[val]++;
	}
	for(auto it=hsh.begin();it!=hsh.end();it++)
	{
		if(it->second >= k)
		{
			cout<<0<<endl;
			return 0;
		}
		a.pb(mp(it->second, it->first));
	}
	// for(i=0;i<sz(a);i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	vector<pii> top(sz(a)+2), bottom(sz(a)+2);
	ll cur1=0;
	ll cur2=0;
	for(i=0;i<sz(a);i++)
	{
		if(i!=0)
			cur2 += cur1*(abs(a[i].ss-a[i-1].ss));
		top[i] = mp(cur1, cur2);
		cur1 += a[i].ff;
	}
	cur1 = 0;
	cur2 = 0;
	for(i=sz(a)-1;i>=0;i--)
	{
		if(i!=sz(a)-1)
			cur2 += cur1*(abs(a[i].ss-a[i+1].ss));
		bottom[i] = mp(cur1, cur2);
		cur1 += a[i].ff;
	}

	ll ans = LLONG_MAX;
	// for(i=0;i<sz(a);i++)
	// 	cout<<top[i].ff<<" "<<top[i].ss<<endl;
	// cout<<endl;
	// for(i=0;i<sz(a);i++)
	// 	cout<<bottom[i].ff<<" "<<bottom[i].ss<<endl;
	for(i=0;i<sz(a);i++)
	{
		ll topcnt = top[i].ff;
		ll topmoves = top[i].ss;
		ll botcnt = bottom[i].ff;
		ll botmoves = bottom[i].ss;
		ll cur_cnt = a[i].ff;
		ll more_needed = k - cur_cnt;
		if(topcnt >= more_needed)
			ans = min(ans, topmoves - topcnt + more_needed);
		if(botcnt >= more_needed)
			ans = min(ans, botmoves - botcnt + more_needed);
		if(cur_cnt + botcnt >= more_needed)
			ans = min(ans, topmoves - topcnt + botmoves - botcnt + more_needed);
	}
	cout<<ans<<endl;
	return 0;
}