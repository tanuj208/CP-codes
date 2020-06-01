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

bool valid(ll med_sal, vector<pii>& v, ll s)
{
	ll n = sz(v);
	ll x = n/2;
	ll total = 0;
	ll cnt = 0;
	ll i;
	for(i=0;i<n;i++)
	{
		if(v[i].ss < med_sal)
		{
			total += v[i].ff;
			cnt++;
		}
	}
	if(cnt > x)
		return false;
	for(i=0;i<n;i++)
	{
		if(v[i].ss < med_sal)
			continue;
		if(cnt<x)
		{
			total += min(med_sal, v[i].ff);
			cnt++;
		}
		else
			total += max(med_sal, v[i].ff);
	}
	if(total <= s)
		return true;
	else
		return false;
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
		ll n,s;
		cin>>n>>s;
		vector<pii> v;
		ll i;
		for(i=0;i<n;i++)
		{
			ll l,r;
			cin>>l>>r;
			v.pb(mp(l,r));
		}
		sort(all(v));

		ll l = 0;
		ll r = s;
		ll mid;
		while(l+1<r)
		{
			mid = (l+r)/2;
			if(valid(mid, v, s))
				l = mid;
			else
				r = mid - 1;
		}
		while(valid(mid, v, s) && mid <= s)
			mid++;
		while(!valid(mid, v, s) && mid > 0)
			mid--;
		cout<<mid<<endl;
	}
	return 0;
}