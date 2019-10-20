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

set<ll> x;
vector<ll> c;
vector<ll> ad[100005];

void dfs(ll v)
{
	ll i;
	bool flag = false;
	if(c[v]==0)
		flag=true;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(c[x]==0)
			flag=true;
		dfs(x);
	}
	if(!flag)
		x.insert(v);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	c.pb(-1);
	ll root;
	for(i=0;i<n;i++)
	{
		ll pi,ci;
		cin>>pi>>ci;
		c.pb(ci);
		if(pi!=-1)
			ad[pi].pb(i+1);
		else
			root=i+1;
	}
	dfs(root);
	if(sz(x)==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(auto it=x.begin();it!=x.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}