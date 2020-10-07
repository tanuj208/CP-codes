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

map<pii,set<pii> > cntt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<pii> p;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		p.pb(mp(x,y));
	}
	ll j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ll x=p[j].ff-p[i].ff;
			ll y=p[j].ss-p[i].ss;
			if(x==0)
				cntt[mp(1,0)].insert(mp(p[i].ff, 1));
			else if(y==0)
				cntt[mp(0,1)].insert(mp(p[i].ss, 1));
			else
			{
				ll 	gcd = __gcd(x,y);
				x/=gcd;
				y/=gcd;
				ll num=y*p[i].ff-x*p[i].ss;
				ll den=y;
				gcd=__gcd(num,den);
				num/=gcd;
				den/=gcd;
				cntt[mp(x, y)].insert(mp(num,den));
			}
		}
	}
	vector<ll> arr;
	for(auto it=cntt.begin();it!=cntt.end();it++)
		arr.pb(sz(it->second));
	ll cum=0;
	for(i=0;i<sz(arr);i++)
		cum+=arr[i];
	ll ans=0;
	for(i=0;i<sz(arr);i++)
	{
		cum-=arr[i];
		ans+=arr[i]*cum;
	}
	cout<<ans<<endl;
	return 0;
}