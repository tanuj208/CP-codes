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

set<ll> get_intersection(set<ll>& a, set<ll>& b)
{
	set<ll> ret;
	auto it1=a.begin();
	auto it2=b.begin();
	while(it1!=a.end() && it2!=b.end())
	{
		if(*it1==*it2)
		{
			ret.insert(*it1);
			it1++;
			it2++;
		}
		else if(*it1<*it2)
			it1++;
		else
			it2++;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll i;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	sort(all(a));
	map<ll,ll> m;
	map<ll,ll> m2;
	for(i=0;i<n;i++)
	{
		ll x=a[i];
		ll cnt=0;
		while(x!=0)
		{			
			m[x]++;
			if(m[x]<=k)
				m2[x]+=cnt;
			cnt++;
			x/=2;
		}
	}
	ll ans=LLONG_MAX;
	for(auto it=m.begin();it!=m.end();it++)
	{
		if(it->second < k)
			continue;
		ll x=it->first;
		ans=min(ans, m2[x]);
	}
	cout<<ans<<endl;
	return 0;
}