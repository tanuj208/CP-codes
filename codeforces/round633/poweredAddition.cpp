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

bool poss(vector<ll> a, ll mx_val)
{
	ll i;
	ll n = a.size();
	a[n-1] += mx_val;
	for(i=n-2;i>=0;i--)
	{
		if(a[i+1] < a[i])
			return false;
		if((a[i+1] - a[i]) > mx_val)
			a[i] += mx_val;
		else
			a[i] = a[i+1];
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll p[45];
	p[0] = 1;
	ll i;
	for(i=1;i<=40;i++)
		p[i] = 2 * p[i-1];
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		ll ans;
		for(i=0;i<=40;i++)
		{
			ll mx_val = p[i] - 1;
			if(poss(a, mx_val))
			{
				ans = i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}