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

set<ll> gob[10005];
map<pii, ll> ggs;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll g;
	cin>>g;
	ll i;
	for(i=0;i<g;i++)
	{
		ll x,y;
		cin>>x>>y;
		gob[y].insert(x);
		ggs[mp(x,y)]++;
	}
	ll m;
	cin>>m;
	for(i=0;i<m;i++)
	{
		ll x,y,r;
		cin>>x>>y>>r;
		ll yy;
		for(yy=max((ll)0, y-r);yy<=min(y+r, (ll)1e4);yy++)
		{
			if(sz(gob[yy])==0)
				continue;
			ll xx;
			ll tmp=sqrt(r*r-(yy-y)*(yy-y));
			ll l=x-tmp;
			ll r=x+tmp;
			auto it1=gob[yy].lower_bound(l);
			auto it2=gob[yy].upper_bound(r);
			// it2--;
			if(it1==gob[yy].end() || it2==gob[yy].begin())
				continue;
			gob[yy].erase(it1, it2);
		}
	}
	ll ans=0;
	for(i=0;i<=10000;i++)
	{
		for(auto it=gob[i].begin();it!=gob[i].end();it++)
		{
			ll x=*it;
			ll y=i;
			ans+=ggs[mp(x,y)];
		}
	}
	cout<<ans<<endl;
	return 0;
}