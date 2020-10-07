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

ll pick(vector<ll>& a, ll pick_cnt, bool small)
{
	ll i;
	ll ans = 1;
	ll cnt = 0;
	if(small)
	{
		for(i=a.size()-1;i>=0;i--)
		{
			ans *= a[i];
			cnt++;
			if(cnt == pick_cnt)
				break;
		}
		return ans;
	}
	for(i=0;i<sz(a);i++)
	{
		ans *= a[i];
		cnt++;
		if(cnt == pick_cnt)
			break;
	}
	return ans;
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
		vector<ll> pos;
		vector<ll> neg;
		bool zero = false;
		ll i;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			if(val < 0)
				neg.pb(-val);
			else if(val > 0)
				pos.pb(val);
			else
				zero = true;
		}
		if(n == 5)
		{
			if(zero)
			{
				cout<<0<<endl;
				continue;
			}
			ll ans = pick(pos, sz(pos), false) * pick(neg, sz(neg), false);
			if(sz(neg) % 2 != 0)
				ans = -ans;
			cout<<ans<<endl;
			continue;
		}
		sort(all(neg));
		reverse(all(neg));
		sort(all(pos));
		reverse(all(pos));
		ll ans;
		if(zero)
			ans = 0;
		else
			ans = LLONG_MIN;

		if(sz(pos) == 0 && sz(neg) >= 5)
			ans = max(ans, -pick(neg, 5, true));
		if(sz(pos) >= 1 && sz(neg) >= 4)
			ans = max(ans, pick(pos, 1, false) * pick(neg, 4, false));
		if(sz(pos) >= 3 && sz(neg) >= 2)
			ans = max(ans, pick(pos, 3, false) * pick(neg, 2, false));
		if(sz(pos) >= 5)
			ans = max(ans, pick(pos, 5, false));
		cout<<ans<<endl;
	}
	return 0;
}
