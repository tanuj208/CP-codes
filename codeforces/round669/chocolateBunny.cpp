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

ll query(ll i, ll j)
{
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	fflush(stdout);
	ll x;
	cin>>x;
	return x;
}

int main()
{
	ll n;
	cin>>n;
	ll a = 0;
	ll b = 1;
	ll i;
	vector<ll> ans(n, -1);
	vector<ll> vis(n+1, 0);
	for(i=0;i<n-1;i++)
	{
		ll x = query(a,b);
		ll y = query(b,a);
		if(x>y)
		{
			ans[a] = x;
			vis[x]=1;
			a = b;
			b++;
		}
		else
		{
			ans[b] = y;
			vis[y]=1;
			b++;
		}
	}
	ll rem;
	for(i=1;i<=n;i++)
		if(vis[i] == 0)
			rem = i;
	cout<<"! ";
	for(i=0;i<n;i++)
	{
		if(ans[i] == -1)
			ans[i] = rem;
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
