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

vector<ll> ad[100005];
vector<ll> p(100005);
vector<ll> s(100005);

ll dfs(ll v)
{
	ll i;
	ll ans=0;
	if(s[v]!=-1)
	{
		if(v==1)
			ans+=s[v];
		for(i=0;i<sz(ad[v]);i++)
		{
			ll x=ad[v][i];
			ans+=dfs(x);
		}
		return ans;
	}
	ll parVal=s[p[v]];
	ll minVal=LLONG_MAX;
	ll sum=0;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		ll val=s[x];
		if(val<parVal)
		{
			cout<<-1<<endl;
			exit(0);
		}
		minVal=min(minVal, val-parVal);
		sum+=val-parVal;
		ans+=dfs(x);
	}
	if(minVal==LLONG_MAX)
		return ans;
	sum-=(sz(ad[v])-1)*minVal;
	ans+=sum;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		ll pa;
		cin>>pa;
		ad[pa].pb(i);
		p[i]=pa;
	}
	for(i=1;i<=n;i++)
	{
		ll val;
		cin>>val;
		s[i]=val;
	}
	cout<<dfs(1)<<endl;
	return 0;
}