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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a;
		vector<ll> col(n+2, -1);
		ll i;
		bool all_eq = true;
		bool cons_eq = false;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		for(i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
				all_eq = false;
			if(a[i] == a[i-1])
				cons_eq = true;
		}
		if(a[0] == a[n-1])
			cons_eq = true;
		if(all_eq)
		{
			cout<<1<<endl;
			for(i=0;i<n;i++)
				cout<<1<<" ";
			cout<<endl;
			continue;
		}
		if(n%2==0)
		{
			cout<<2<<endl;
			ll cur=0;
			for(i=0;i<n;i++)
			{
				cout<<cur+1<<" ";
				cur^=1;
			}
			cout<<endl;
			continue;
		}
		if(cons_eq)
		{
			cout<<2<<endl;
			bool flag = false;
			ll cur=0;
			for(i=0;i<n;i++)
			{
				cout<<1+cur<<" ";
				if(!flag && a[i] == a[(i+1)%n])
					flag = true;
				else
					cur = cur ^ 1;
			}
			cout<<endl;
			continue;
		}
		cout<<3<<endl;
		ll cur=0;
		for(i=0;i<n-1;i++)
		{
			cout<<1+cur<<" ";
			cur ^= 1;
		}
		cout<<3<<endl;
	}
	return 0;
}