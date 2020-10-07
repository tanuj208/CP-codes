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

vector<ll> take_input(ll n)
{
	ll i;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		ll vl;
		cin>>vl;
		a.pb(vl);
	}
	return a;
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
		vector<ll> a,b,c;
		a = take_input(n);
		b = take_input(n);
		c = take_input(n);
		vector<ll> ans;
		ll i;
		ans.pb(a[0]);
		for(i=1;i<n-1;i++)
		{
			if(a[i] == ans[i-1])
				ans.pb(b[i]);
			else
				ans.pb(a[i]);
		}
		if(a[n-1] != ans[0] && a[n-1] != ans[n-2])
			ans.pb(a[n-1]);
		else if(b[n-1] != ans[0] && b[n-1] != ans[n-2])
			ans.pb(b[n-1]);
		else if(c[n-1] != ans[0] && c[n-1] != ans[n-2])
			ans.pb(c[n-1]);
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
