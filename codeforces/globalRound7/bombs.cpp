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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> p,q;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		p.pb(val-1);
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		q.pb(val-1);
	}
	ll ss=sqrt(n);
	vector<set<ll>> x; // sqrt decomp
	i=0;
	set<ll> tmp;
	while(i<n)
	{
		ll cnt=0;
		while(cnt!=ss && i<n)
		{
			tmp.insert(p[i]);
			i++;
			cnt++;
		}
		x.pb(tmp);
	}
	ll j;
	// for(i=0;i<sz(x);i++)
	// {
	// 	for(auto it=x[i].begin();it!=x[i].end();it++)
	// 		cerr<<*it<<" ";
	// 	cerr<<endl;
	// }
	vector<ll> ans;
	ans.pb(*x[sz(x)-1].rbegin());
	for(i=0;i<n-1;i++)
	{
		ll xx=q[i];
		ll tmp2 = xx/ss -1;
		ll mx_val;
		if(tmp2 == -1 || sz(x[tmp2])==0)
			mx_val=0;
		else
			mx_val = *x[tmp2].rbegin();
		for(j=max((ll)0, tmp2*ss);j<=q[i];j++)
			mx_val=max(mx_val, p[j]);
		for(j=tmp2+1;j<sz(x);j++)
		{
			if(x[j].find(mx_val)==x[j].end())
				mx_val = *x[j].rbegin();
			x[j].erase(mx_val);
		}
		ans.pb(*x[sz(x)-1].rbegin());
	}
	for(i=0;i<sz(ans);i++)
		cout<<ans[i]+1<<" ";
	cout<<endl;
	return 0;
}