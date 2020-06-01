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
	if(temp == LLONG_MAX)
		return LLONG_MAX;
	if (y%2 == 0)
	{
		if(temp > 1e18/temp)
			return LLONG_MAX;
		return temp*temp;
	}
	else
	{
		if(x > 1e18/temp || x*temp > 1e18/temp)
			return LLONG_MAX;
		return x*temp*temp; 
	}
}

ll pr_cnt(ll x)
{
	ll cnt=0;
	ll tmp =x;
	for(ll i=2;i<=x;i++)
	{
		ll tmpcnt = 0;
		while(tmp != 1 && tmp%i == 0)
		{
			tmp/=i;
			tmpcnt++;
		}
		if(tmpcnt >= 2)
			return 0;
		else if(tmpcnt == 1)
			cnt++;
	}
	return cnt;
}

ll get_lt(ll x, ll i)
{
	ll l = 1;
	ll r = 1e18;
	ll mid;
	while(l<r-1)
	{
		mid = (l+r)/2;
		if(power(mid, i) > x)
			r = mid - 1;
		else
			l = mid;
	}
	if(l == r-1)
	{
		if(power(r, i) <= x)
			return r;
		else
			return l;
	}
	return l;
}

ll get_ith_root(ll x, ll i, ll upper_lt) {
	for(ll j = upper_lt; j>=0; j--)
	{
		if(power(j, i) <= x)
			return j;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,i;
	cin>>t;
	vector<ll> mob(65, -1);
	mob[1] = 1;
	for(i=2;i<=63;i++)
	{
		ll x = pr_cnt(i);
		if(x!=0 && x%2 == 0)
			x = 1;
		else if(x%2==1)
			x = -1;
		mob[i] = x;
	}
	vector<pii> q;
	for(i=0;i<t;i++)
	{
		ll n;
		cin>>n;
		q.pb(mp(n, i));
	}
	sort(all(q));
	reverse(all(q));
	vector<ll> lt(65);
	for(i=2;i<=63;i++)
		lt[i] = get_lt(1e18, i);
	vector<ll> ans(t+1);
	for(i=0;i<sz(q);i++)
	{
		ll a=0;
		ll j;
		ll num = q[i].ff;
		ll idx = q[i].ss;
		for(j=3;j<=63-__builtin_clzll(num);j++)
		{
			if(mob[j] == 0)
				continue;
			ll tmp = get_ith_root(num, j, lt[j]);
			lt[j] = tmp;
			a += (tmp-1)*mob[j];
		}
		a += (sqrt(num)-1)*mob[2];
		ans[idx] = num-1-a;
	}
	for(i=0;i<t;i++)
		cout<<ans[i]<<endl;
	return 0;
}