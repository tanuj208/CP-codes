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

vector<ll> a;
vector<ll> mn(300005);
ll n,m;

bool check(ll x)
{
	ll cur=0;
	ll i;
	for(i=0;i<n;i++)
	{
		ll xx;
		if(a[i]>cur)
			xx=m-(a[i]-cur);
		else
			xx=cur-a[i];
		if(x>=xx)
			continue;
		if(a[i]>=cur)
			cur=a[i];
		else
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=n-1;i>=0;i--)
	{
		if(i==n-1)
			mn[i]=a[i];
		else
			mn[i]=min(mn[i+1],a[i]);
	}
	ll l = 0;
	ll r=1000000;
	ll mid=(l+r)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	while(check(mid) && mid>0)
		mid--;
	while(!check(mid))
		mid++;
	cout<<mid<<endl;
	return 0;
}