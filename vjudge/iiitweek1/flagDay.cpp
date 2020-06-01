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

vector<ll> ans;

pii get_old(vector<ll>& dn)
{
	if(ans[dn[0]] != 0)
		return mp(0, ans[dn[0]]);
	else if(ans[dn[1]] != 0)
		return mp(1, ans[dn[1]]);
	else if(ans[dn[2]] != 0)
		return mp(2, ans[dn[2]]);
	else
		return mp(-1, 0);
}

void incr(pii& x)
{
	x.ff = (x.ff+1)%3;
	x.ss = 1+x.ss%3;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ans.resize(n+1, 0);
	ll i;
	for(i=0;i<m;i++)
	{
		vector<ll> dn(3);
		cin>>dn[0]>>dn[1]>>dn[2];
		pii x = get_old(dn);
		incr(x);
		ans[dn[x.ff]] = x.ss;
		incr(x);
		ans[dn[x.ff]] = x.ss;
		incr(x);
		ans[dn[x.ff]] = x.ss;
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}