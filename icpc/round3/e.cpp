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

vector<ll> segtree(800010, 0);
vector<ll> lazy(800010, 0);
map<ll,ll> maap;

//query returns the required answer between given ranges
ll query(ll l, ll r,ll index,ll low, ll high) //verify return type
{
	//if we visit a node it must hold the correct value
	if(lazy[index]){
		//means whole of the range was eligible to be updated
		// so as we visited this node we will update it, so that it holds correct value
		segtree[index] += lazy[index];
		if(high!=low){
			lazy[2*index] += lazy[index]; 
			lazy[2*index+1] += lazy[index]; 
		}
		lazy[index] = 0;
	}
	if(r<low || l>high) return 0;
	
	ll m=(low+high)>>1;
	if(l<=low && high<=r)
	{
		// cout<<segtree[index]<<"seg"<<endl;
		return segtree[index];//as it holds the up-to-date value
	}
	else{
		ll xx = max(query(l,r,2*index,low,m), query(l,r,2*index+1,m+1,high));
		// cout<<xx<<"DFFD"<<endl;
		return xx;
	}
}

void update(ll l, ll r,ll index,ll low, ll high,ll val){
	//if we visit a node it must hold the correct value
	ll m=(low+high)/2;

	// resolve the old lazy on this node first
	if(lazy[index]){
		//means whole of the range was eligible to be updated, so as we visited this node we will update it
		segtree[index] += lazy[index];
		// cout<<segtree[index]<<" "<<lazy[index]<<"F\n";
		if(high!=low){ 
			lazy[2*index] += lazy[index]; 
			lazy[2*index+1] += lazy[index]; 
		}
		lazy[index] = 0;
	}

	// then impose new lazy onto it
	if(l<=low && high<=r){
		segtree[index] += val;//make it completely up-to-date
		// cout<<segtree[index]<<"VF\n";
		if(high!=low){
			lazy[2*index] += val; 
			lazy[2*index+1] += val;
		}
	}
	else if(r<low || l>high) return;
	else{
		update(l,r,2*index,low,m,val);
		update(l,r,2*index+1,m+1,high,val);
		segtree[index]=max(segtree[2*index], segtree[2*index+1]);
	}
}

// map<pii,ll> anMap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<pii> a;
	ll i;
	set<ll> tmp;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(y,x));
		tmp.insert(x);
		tmp.insert(y);
	}
	ll cnt=1;
	for(auto it=tmp.begin();it!=tmp.end();it++)
	{
		maap[*it] = cnt;
		cnt++;
	}
	sort(all(a));
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ll l=a[i].ss;
		ll r=a[i].ff;
		l = maap[l];
		r = maap[r];
		if(r==l+1)
		{
			ll cnt = query(l, l+1, 1, 1, cnt-1) - query(l, l, 1, 1, cnt-1) - query(l+1, l+1, 1, 1, cnt-1);
			if(cnt < k)
			{
				update(l,r,1,1,cnt-1,1);
				ans++;
			}
			continue;
		}
		ll xx=query(l+1, r-1, 1, 1, cnt-1);
		if(xx < k)
		{
			ans++;
			// anMap[mp(l,r)]++;
			update(l, r, 1, 1, cnt-1, 1);
		}
	}
	cout<<ans<<endl;
	return 0;
}

