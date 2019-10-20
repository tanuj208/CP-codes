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

ll countSetBits(ll x)
{
	bool ans=false;
	while(x!=0)
	{
		if(x%2==1)
			ans=!ans;
		x/=2;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,z;
	cin>>t;
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n,q;
		cin>>n>>q;
		vector<ll> a;
		ll i;
		set<ll> odds;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
			if(countSetBits(val))
				odds.insert(i);
		}
		while(q--)
		{
			ll p,v;
			cin>>p>>v;
			ll x1=countSetBits(v);
			ll x2=countSetBits(a[p]);
			if(x1 && !x2)
				odds.insert(p);
			else if(!x1 && x2)
				odds.erase(p);
			if(sz(odds)%2==0)
				cout<<n<<" ";
			else
			{
				ll i1=*odds.begin();
				auto it=odds.end();
				it--;
				ll i2=*it;
				cout<<max(n-i1-1, i2)<<" ";
			}
			a[p]=v;
		}
		cout<<endl;
	}
	return 0;
}