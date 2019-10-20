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

map<ll,map<ll,ll> > x;
map<ll,pii> dp;

void func(ll val)
{
	if(dp.find(val)!=dp.end())
		return;
	ll sp=0;
	ll val2=val;
	if(x.find(val)==x.end())
	{
		if(x.upper_bound(val)!=x.end())
		{
			auto it=x.upper_bound(val);
			sp+=it->ff-val;
			val=it->ff;
		}
		else
		{
			dp[val]=mp(0,1);
			return;
		}
	}
	ll ans=0;
	ll was=LLONG_MAX;
	for(auto it=x[val].begin();it!=x[val].end();it++)
	{
		func(it->ff);
		if(was > dp[it->ff].ff)
			was=dp[it->ff].ff, ans=dp[it->ff].ss*it->ss;
		else if(was==dp[it->ff].ff)
			ans+=dp[it->ff].ss*it->ss;
	}
	dp[val2]=mp(was+sp, ans);
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
	for(i=0;i<n;i++)
	{
		ll l,r;
		cin>>l>>r;
		x[r][l]++;
	}
	for(auto it=x.begin();it!=x.end();it++)
		func(it->first);
	ll sp=LLONG_MAX;
	ll ans=0;

	for(auto it=dp.begin();it!=dp.end();it++)
	{
		cout<<it->ff<<" "<<it->ss.ff<<" "<<it->ss.ss<<endl;
	}
	for(auto it=dp.begin();it!=dp.end();it++)
	{
		ll was=it->ss.ff;
		ll an=it->ss.ss;
		// cout<<was+it->ff<<endl;
		if(sp>was+it->ff)
			ans=an, sp=was+it->ff;
		else if(sp==was+it->ff)
			ans+=an;
	}
	cout<<ans<<endl;
	return 0;
}