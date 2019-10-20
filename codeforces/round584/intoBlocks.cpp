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

vector<ll> par(200005, -1);

ll parent(ll x)
{
	if(par[x]==-1 || par[x]==x)
		return x;
	par[x]=parent(par[x]);
	return par[x];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	vector<ll> a;
	vector<ll> ad[200005];
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		ll xx=sz(ad[val]);
		if(xx>0)
			par[i]=ad[val][xx-1];
		ad[val].pb(i);
	}
	vector<bool> updated(n+5, false);
	ll ans=0;
	for(i=1;i<n;i++)
	{
		ll x1=a[parent(i)];
		ll x2=a[parent(i-1)];
		if(x1!=x2 && ad[x2][sz(ad[x2])-1] < i)
			continue;
		if(x1!=x2 && updated[x1])
		{
			par[i-1]=i;
			ans+=sz(ad[x2]);
			updated[x2]=true;
		}
		else if(x1!=x2)
		{
			if(sz(ad[x1])<sz(ad[x2]))
			{
				ans+=sz(ad[x1]);
				par[i]=i-1;
				updated[x1]=1;
			}
			else
			{
				ans+=sz(ad[x2]);
				par[i-1]=i;
				updated[x2]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}