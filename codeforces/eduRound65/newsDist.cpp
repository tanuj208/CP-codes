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

vector<ll> p(500005,-1);
vector<ll> c(500005,1);

ll parent(ll v)
{
	if(p[v]==-1)
		return v;
	p[v]=parent(p[v]);
	return p[v];
}

void join_groups(ll v1,ll v2)
{
	if(parent(v1)!=parent(v2))
	{
		ll x1=parent(v1);
		ll x2=parent(v2);
		if(c[x1]<=c[x2])
		{
			p[x1]=x2;
			c[x2]+=c[x1];
		}
		else
		{
			p[x2]=x1;
			c[x1]+=c[x2];
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=0;i<m;i++)
	{
		ll k;
		cin>>k;
		ll j;
		ll prev=-1;
		for(j=0;j<k;j++)
		{
			ll val;
			cin>>val;
			if(prev!=-1)
				join_groups(prev, val);
			prev=val;
		}
	}
	vector<ll> ans(500005, 0);
	for(i=1;i<=n;i++)
	{
		ll x=parent(i);
		ans[x]++;
	}
	for(i=1;i<=n;i++)
		cout<<ans[parent(i)]<<" ";
	cout<<endl;
	return 0;
}		