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
	ll n,m;
	cin>>n>>m;
	vector<ll> x;
	ll i;
	vector<ll> ans(n+5, 0);
	vector<ll> anArr(n+5, 0);
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		x.pb(val);
	}
	for(i=1;i<m;i++)
	{
		ll a=min(x[i], x[i-1]);
		ll b=max(x[i], x[i-1]);
		if(a==b)
			continue;
		ans[1]+=b-a;
		ans[a+1]+=-1;
		ans[b]+=1;
		anArr[a]+=(b-1)-(b-a);
		anArr[b]+=(a)-(b-a);
	}
	ll prev_val = ans[1];
	ans[1]+=anArr[1];
	for(i=2;i<=n;i++)
	{
		ans[i]+=prev_val;
		prev_val = ans[i];
		ans[i]+=anArr[i];
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}