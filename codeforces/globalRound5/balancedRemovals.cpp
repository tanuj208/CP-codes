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

map<ll, map<ll, map<ll, ll>>> pts; // pts[x_cor][y_cor][z_cor] = index

void erase(ll x, ll y, ll z)
{
	pts[x][y].erase(z);
	if(sz(pts[x][y])==0)
		pts[x].erase(y);
	if(sz(pts[x])==0)
		pts.erase(x);
	return;
}

void find_another(ll x, ll y, ll z)
{
	auto it = pts.lower_bound(x);
	if(it==pts.end())
		it--;
	ll x1=it->first;

	auto it2 = pts[x1].lower_bound(y);
	if(it2==pts[x1].end())
		it2--;
	ll y1=it2->first;

	auto it3 = pts[x1][y1].lower_bound(z);
	if(it3==pts[x1][y1].end())
		it3--;
	ll z1=it3->first;
	ll idx = it3->second;
	cout<<1+idx<<endl;
	erase(x1, y1, z1);
	return;
}

void find(ll x, ll y, ll z)
{
	if(pts.find(x)==pts.end())
		return;
	if(pts[x].find(y)==pts[x].end())
		return;
	if(pts[x][y].find(z)==pts[x][y].end())
		return;
	ll idx1 = pts[x][y][z];
	cout<<1+idx1<<" ";
	erase(x, y, z);
	find_another(x, y, z);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<pair<ll,pii>> points;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		points.pb(mp(x, mp(y, z)));
		pts[x][y][z] = i;
	}
	sort(all(points));
	for(i=0;i<n;i++)
	{
		ll x=points[i].ff;
		ll y=points[i].ss.ff;
		ll z=points[i].ss.ss;
		find(x, y, z);
	}
	return 0;
}