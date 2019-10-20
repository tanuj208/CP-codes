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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	vector<ll> mn(n+5, -1);
	vector<ll> mx(n+5, -1);
	stack<pii> st;
	for(i=n-1;i>=0;i--)
	{
		while(!st.empty())
		{
			pii x=st.top();
			if(x.ff>a[i])
				mn[x.ss] = i;
			else
				break;
			st.pop();
		}
		st.push(mp(a[i], i));
	}
	while(!st.empty())
		st.pop();
	for(i=n-1;i>=0;i--)
	{
		while(!st.empty())
		{
			pii x=st.top();
			if(x.ff<a[i])
				mx[x.ss] = i;
			else
				break;
			st.pop();
		}
		st.push(mp(a[i], i));
	}
	vector<ll> mnDp(n+5, 0);
	vector<ll> mxDp(n+5, 0);

	mnDp[0] = a[0];
	mxDp[0] = a[0];

	for(i=1;i<n;i++)
	{
		ll x1=mn[i];
		mnDp[i] = a[i]*(i-x1);
		if(x1!=-1)
			mnDp[i]+=mnDp[x1];
		x1 = mx[i];
		mxDp[i] = a[i]*(i-x1);
		if(x1!=-1)
			mxDp[i]+=mxDp[x1];
	}
	ll ans=0;
	for(i=0;i<n;i++)
		ans+=mxDp[i]-mnDp[i];
	cout<<ans<<endl;
	return 0;
}