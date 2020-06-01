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

ll get_cnt(ll x)
{
	return (x*(x+1))/2;
}

ll b1(ll rem)
{
	ll l = 0;
	ll r = 1000000000;
	ll mid;
	while(l<r-1)
	{
		mid = (l+r)/2;
		if(get_cnt(mid) > rem)
			r=mid-1;
		else
			l = mid;
	}
	if(l==r)
		return l;
	if(get_cnt(r) <= rem)
		return r;
	else
		return l;
}

ll c2(ll x, ll tmp)
{
	ll tt = tmp*x;
	ll tt2 = x*x;
	if(tt > 1e18 - tt2)
		return -1;
	else
		return tt+tt2;
}

ll c3(ll x, ll tmp)
{
	ll tt = tmp*x;
	ll tt2 = x*(x+1);
	if(tt > 1e18 - tt2)
		return -1;
	else
		return tt+tt2;
}

ll b2(ll rem, ll tmp)
{
	ll l=0;
	ll r=1000000000;
	ll mid;
	while(l<r-1)
	{
		mid = (l+r)/2;
		ll x = c2(mid, tmp);
		if(x == -1 || x > rem)
			r = mid-1;
		else
			l = mid;
	}
	if(l==r)
		return l;
	if(c2(r, tmp) <= rem)
		return r;
	else
		return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll l,r;
		cin>>l>>r;
		bool flag = true;
		if(r>l)
		{
			flag = false;
			swap(l,r);
		}
		ll ans=0;
		ans += b1(l-r);
		l -= get_cnt(ans);
		if(l==r)
			flag = true;
		ll tmp = ans;
		ll pos = b2(l, tmp);
		if(c2(pos+1, tmp) <= l && c2(pos+1, tmp) >= 0)
			pos++;
		l -= c2(pos, tmp);
		ans += pos;

		if(c3(pos, tmp) <=r && c3(pos, tmp) >= 0);
		else
			pos--;
		ans += pos;
		r -= c3(pos, tmp);

		if(!flag)
			swap(l,r);

		cout<<ans<<" "<<l<<" "<<r<<endl;
	}
	return 0;
}