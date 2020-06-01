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
ll n;
vector<ll> ad[500005];
vector<ll> vis(5e5+5, 0);

void dfs(ll v, ll par)
{
	if(vis[v]==1)
		return;
	vis[v]=1;
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x!=par)
			dfs(x,v);
	}
	return;
}

bool check_tree()
{
	dfs(1,0);
	ll i;
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	multiset<pair<pii,ll>> str, rev;
	vector<pair<pii,ll>> range;
	ll i;
	for(i=0;i<n;i++)
	{
		ll l,r;
		cin>>l>>r;
		range.pb(mp(mp(l,r), i+1));
	}
	sort(all(range));
	ll edges=0;

	for(i=0;i<n;i++)
	{
		ll l=range[i].ff.ff;
		ll r=range[i].ff.ss;
		ll idx=range[i].ss;
		while(sz(rev)!=0 && rev.begin()->ff.ff < l)
		{
			auto it=rev.begin();
			ll r1=it->ff.ff;
			ll l1=it->ff.ss;
			ll idx1=it->ss;
			rev.erase(it);
			auto it3=str.find(mp(mp(l1, r1), idx1));
			auto it2=it3;
			it2++;
			for(;it2!=str.end();it2++)
			{
				ll idx2=it2->ss;
				edges++;
				ad[idx1].pb(idx2);
				ad[idx2].pb(idx1);
				if(edges==n)
				{
					cout<<"NO\n";
					return 0;
				}
			}
			str.erase(it3);
		}
		str.insert(mp(mp(l,r), idx));
		rev.insert(mp(mp(r,l), idx));
	}
	while(sz(rev)!=0)
	{
		auto it=rev.begin();
		ll r1=it->ff.ff;
		ll l1=it->ff.ss;
		ll idx1=it->ss;
		rev.erase(it);
		auto it3=str.find(mp(mp(l1, r1), idx1));
		auto it2=it3;
		it2++;
		for(;it2!=str.end();it2++)
		{
			ll idx2=it2->ss;
			edges++;
			ad[idx1].pb(idx2);
			ad[idx2].pb(idx1);
			if(edges==n)
			{
				cout<<"NO\n";
				return 0;
			}
		}
		str.erase(it3);
	}
	if(check_tree())
		cout<<"YES\n";
	else
		cout<<"NO\n";
	// for(i=1;i<=n;i++)
	// {
	// 	for(ll j=0;j<sz(ad[i]);j++)
	// 	{
	// 		cout<<"Edge bw "<<i<<" "<<ad[i][j]<<endl;
	// 	}
	// }
	return 0;
}