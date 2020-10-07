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

vector<ll> get_max_idx(vector<pii>& a)
{
	ll i;
	ll max_val = 0;
	vector<ll> idx;
	for(i=0;i<sz(a);i++)
	{
		if(a[i].ff > max_val)
		{
			max_val = a[i].ff;
			idx.clear();
			idx.pb(i);
		}
		else if(a[i].ff == max_val)
			idx.pb(i);
	}
	return idx;
}

void fill_array(vector<ll>& target, vector<ll>& idx, vector<ll>& vis, vector<pii>& gcd_arr, vector<pii>& a)
{
	for(ll i=0;i<sz(idx);i++)
	{
		ll idd = idx[i];
		ll id2 = gcd_arr[idd].ss;
		target.pb(a[id2].ff);
		vis[id2] = 1;
	}
	return;
}

vector<pii> get_gcd_array(vector<pii>& a, vector<ll>& vis, ll cur_gcd)
{
	vector<pii> gcd_array;
	for(ll i=0;i<sz(a);i++)
	{
		if(vis[i] == 1)
			continue;
		ll gcd_val = __gcd(cur_gcd, a[i].ff);
		gcd_array.pb(mp(gcd_val, a[i].ss));
	}
	return gcd_array;
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
		vector<pii> a;
		ll i;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(mp(val, i));
		}
		vector<ll> max_val_idx = get_max_idx(a);
		vector<ll> ans;
		vector<ll> vis(n+1, 0);
		fill_array(ans, max_val_idx, vis, a, a);
		ll gcd = ans[0];

		while(sz(ans) != n)
		{
			vector<pii> gcd_array = get_gcd_array(a, vis, gcd);
			vector<ll> idx = get_max_idx(gcd_array);
			fill_array(ans, idx, vis, gcd_array, a);
			gcd = gcd_array[idx[0]].ff;
		}
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
