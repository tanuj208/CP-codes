#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

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
vector<ll> dp(100005,0);
ll ans=LLONG_MAX;

void dfs(ll v,ll p)
{
	ll i;
	ll mn=LLONG_MAX;
	ll secondMn=LLONG_MAX;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==p)
			continue;
		dfs(x,v);
		if(dp[x]<mn)
		{
			secondMn=mn;
			mn=dp[x];
		}
		else if(dp[x]>=mn && dp[x]<secondMn)
			secondMn=dp[x];
	}
	// if(v==1)
		// cout<<mn<<" "<<secondMn<<endl;
	if(mn==LLONG_MAX)
		dp[v]=0;
	else
		dp[v]=1+mn;
	if(mn==LLONG_MAX || secondMn == LLONG_MAX)
		return;
	ans=min(ans,mn+secondMn+2);
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
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	if(n==2)
	{
		cout<<"-1\n";
		return 0;
	}
	dfs(1,0);
	// cout<<dp[2]<<endl;
	if(ans==LLONG_MAX)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}