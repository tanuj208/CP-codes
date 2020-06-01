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

ll get_val(ll x, ll y, ll z)
{
	ll a1 = (x-y)*(x-y);
	ll a2 = (y-z)*(y-z);
	ll a3 = (z-x)*(z-x);
	return a1+a2+a3;
}

pii get_closest(ll val, vector<ll>& a)
{
	ll y1=-1, y2=-1;
	ll idx = upper_bound(all(a), val) - a.begin();
	if(idx < sz(a))
		y1 = a[idx];
	idx--;
	if(idx >= 0)
		y2 = a[idx];
	return mp(y1, y2);
}

void update_ans(ll& ans, vector<ll>& mn, vector<ll>& a, vector<ll>& b)
{
	ll i;
	for(i=0;i<sz(mn);i++)
	{
		ll x = mn[i];

		pii y = get_closest(x, a);

		pii z1 = get_closest(x, b);
		pii z2 = get_closest(y.ff, b);
		pii z3 = get_closest(y.ss, b);

		vector<ll> yy{y.ff, y.ss};
		vector<ll> zz{z1.ff, z1.ss, z2.ff, z2.ss, z3.ff, z3.ss};

		for(ll j=0;j<sz(yy);j++)
		{
			for(ll k=0;k<sz(zz);k++)
			{
				if(yy[j] != -1 && zz[k] != -1)
					ans = min(ans, get_val(x, yy[j], zz[k]));
			}
		}
	}
	return;
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
		ll nr,ng,nb;
		cin>>nr>>ng>>nb;
		vector<ll> r,g,b;
		ll i;
		for(i=0;i<nr;i++)
		{
			ll val;
			cin>>val;
			r.pb(val);
		}
		for(i=0;i<ng;i++)
		{
			ll val;
			cin>>val;
			g.pb(val);
		}
		for(i=0;i<nb;i++)
		{
			ll val;
			cin>>val;
			b.pb(val);
		}
		ll ans=LLONG_MAX;
		sort(all(r));
		sort(all(g));
		sort(all(b));
		update_ans(ans, r,g,b);
		update_ans(ans, g,r,b);
		update_ans(ans, b,r,g);
		cout<<ans<<endl;
	}
	return 0;
}