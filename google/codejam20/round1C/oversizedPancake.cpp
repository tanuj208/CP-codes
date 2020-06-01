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

bool check_special_case(map<ll,ll>& hsh)
{
	ll twos=0;
	ll mx_val = 0;
	ll two_val;
	for(auto it=hsh.begin();it!=hsh.end();it++)
	{
		mx_val = max(mx_val, it->first);
		if(it->second == 2)
		{
			twos++;
			two_val = it->first;
		}
		if(twos >= 2)
			return false;
	}
	if(mx_val == two_val)
		return true;
	else
		return false;
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
		ll n,d;
		ll i;
		cin>>n>>d;
		map<ll,ll> hsh;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			hsh[val]++;
		}
		if(n==1)
		{
			cout<<d-1<<endl;
			continue;
		}
		ll mx_hash = 0;
		for(auto it=hsh.begin();it!=hsh.end();it++)
			mx_hash = max(mx_hash, it->second);
		if(d==2)
		{
			if(mx_hash >= 2)
				cout<<0<<endl;
			else
				cout<<1<<endl;
			continue;
		}
		if(mx_hash >= 3)
		{
			cout<<0<<endl;
			continue;
		}
		bool found = false;
		for(auto it=hsh.begin();it!=hsh.end();it++)
		{
			ll tmp = 2 * it->first;
			if(hsh.find(tmp) != hsh.end())
			{
				cout<<1<<endl;
				found = true;
				break;
			}
		}
		if(found)
			continue;
		if(mx_hash == 2 && n>2)
		{
			if(check_special_case(hsh))
				cout<<2<<endl;
			else
				cout<<1<<endl;
			continue;
		}
		if(mx_hash == 2 && n==2)
		{
			cout<<2<<endl;
			continue;
		}
		if(!found)
			cout<<2<<endl;
	}
	return 0;
}