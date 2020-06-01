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

ll get_sum(ll st, ll en)
{
	ll x1 = (en*(en+1))/2;
	ll x2 = ((st-1)*st)/2;
	return x1-x2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll i;
	ll ans=0;
	for(i=b;i<=c;i++)
	{
		ll st = a+i-1;
		ll en = b+i-1;
		// cout<<i<<" "<<st<<" "<<en<<endl;
		if(en < c)
			continue;
		if(st < c)
			st = c;
		if(st > d)
		{
			ll cnt = d-c+1;
			ans += cnt * (b-a+1);
			continue;
		}
		if(en > d)
			en = d;
		ans += get_sum(st-c+1, en-c+1);
		ll lam = d - i + 1;
		if(lam < b)
			ans += (d-c+1) * (b-lam);
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}