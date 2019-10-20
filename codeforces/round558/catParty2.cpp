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

set<pii> x;

bool check()
{
	if(sz(x)==1)
	{
		auto it=x.begin();
		ll x1=it->first;
		ll y1=it->second;
		if(x1==1 || y1==1)
			return true;
		else
			return false;
	}
	if(sz(x)!=2)
		return false;
	auto it=x.begin();
	ll x1=it->first;
	ll y1=it->second;
	it++;
	ll x2=it->first;
	ll y2=it->second;
	if((x1==1 && y1==1) || (x2==1 && y2==1))
		return true;
	if(x1==x2-1 && y2==1)
		return true;
	if(x2==x1-1 && y1==1)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> cnt(100005,0);
	ll i;
	vector<ll> u;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		u.pb(val);
		cnt[val]++;
	}
	map<ll,ll> anMap;
	for(i=1;i<=100000;i++)
		if(cnt[i]!=0)
			anMap[cnt[i]]++;
	for(auto it=anMap.begin();it!=anMap.end();it++)
		x.insert(mp(it->first, it->second));
	for(i=n-1;i>=0;i--)
	{
		// if(i==n-1)
		// {
		// 	for(auto it=x.begin();it!=x.end();it++)
		// 		cout<<it->first<<" "<<it->second<<endl;
		// }
		if(check())
			break;
		ll val=cnt[u[i]];
		cnt[u[i]]--;
		x.erase(mp(val, anMap[val]));
		anMap[val]--;
		if(anMap[val]!=0)
			x.insert(mp(val, anMap[val]));
		if(cnt[u[i]]!=0)
		{
			anMap[val-1]++;
			if(anMap[val-1]!=1)
				x.erase(mp(val-1, anMap[val-1]-1));
			x.insert(mp(val-1, anMap[val-1]));
		}
	}
	cout<<i+1<<endl;
	return 0;
}