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
map<ll,ll> x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<ll> a;
	ll i;
	set<ll> tmp;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		x[val]++;
		tmp.insert(val);
	}
	ll mn = *tmp.begin();
	ll mx = *tmp.rbegin();

	while(k!=0)
	{
		// cerr<<mn<<" "<<mx<<" "<<k<<endl;
		if(x[mn]<=x[mx])
		{
			// cerr<<"F1"<<endl;
			auto it=tmp.begin();
			it++;
			if(it!=tmp.end())
			{
				ll val2 = *it;
				if(x[mn]*(val2-mn) < k)
				{
					k-=x[mn]*(val2-mn);
					mn=val2;
					x[val2]+=x[mn];
					tmp.erase(tmp.begin());
				}
				else
				{
					mn+=k/x[mn];
					cout<<mx-mn<<endl;
					return 0;
				}
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
		else
		{
			// cerr<<"F2"<<endl;
			auto it=tmp.rbegin();
			it++;
			if(it!=tmp.rend())
			{
				ll val2 = *it;
				// cerr<<val2<<endl;
				if(x[mx]*(mx-val2) < k)
				{
					k-=x[mx]*(mx-val2);
					mx=val2;
					auto tmpIt= tmp.end();
					tmpIt--;
					tmp.erase(tmpIt);
					x[val2]+=x[mx];
				}
				else
				{
					mx-=k/x[mx];
					cout<<mx-mn<<endl;
					return 0;
				}
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
	}
	return 0;
}
