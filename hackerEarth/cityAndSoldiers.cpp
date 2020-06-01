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

vector<ll> p(100005, -1);
// vector<ll> s(100005, 1);

ll parent(ll x)
{
	if(p[x]==-1)
		return x;
	p[x] = parent(p[x]);
	return p[x];
}

void dsu(ll x, ll y)
{
	ll x1=parent(x);
	ll x2=parent(y);
	if(x1==x2)
		return;
	p[x1] = x2;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		if(x==1)
		{
			ll a,b;
			cin>>a>>b;
			dsu(a,b);
		}
		else if(x==2)
		{
			ll a;
			cin>>a;
			p[parent(a)] = a;
			p[a]=-1;
		}
		else
		{
			ll a;
			cin>>a;
			cout<<parent(a)<<endl;
		}
	}
	return 0;
}