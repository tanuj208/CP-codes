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

vector<ll> ad[10005];
vector<ll> one,two;
ll n;
bool fll=true;

void reset(ll n)
{
	ll i;
	fll=true;
	one.clear();
	two.clear();
	for(i=0;i<=n;i++)
		ad[i].clear();
	return;
}

void ddfs(ll v,ll p)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		if(fll)
			two.pb(x);
		else
			one.pb(x);
		fll=!fll;
		ddfs(x,v);
	}
	return;
}

void dfs(ll v,ll p, bool flag)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		if(flag)
			two.pb(x);
		else
			one.pb(x);
		dfs(x,v,!flag);
	}
	return;
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
		cin>>n;
		reset(n);
		ll i;
		for(i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			ad[u].pb(v);
			ad[v].pb(u);
		}
		one.pb(1);
		dfs(1,-1,true);
		if(sz(one)==sz(two))
			cout<<1<<endl;
		else
		{
			one.clear();
			two.clear();
			cout<<2<<endl;
			one.pb(1);
			ddfs(1,-1);
		}

		for(i=0;i<n/2;i++)
			cout<<one[i]<<" ";
		cout<<endl;
		for(i=0;i<n/2;i++)
			cout<<two[i]<<" ";
		cout<<endl;
	}
	return 0;
}