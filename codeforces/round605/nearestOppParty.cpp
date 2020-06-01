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

ll n;
vector<ll> dp(2e5+5, -1);
vector<ll> a;

bool diff_parity(ll x,ll y)
{
	if(x==-1 || y==-1)
		return false;
	if(x%2==0)
	{
		if(y%2==0)
			return false;
		else
			return true;
	}
	else
	{
		if(y%2==1)
			return false;
		else
			return true;
	}
}

ll rec(ll i)
{
	if(dp[i]!=-1 && dp[i]!=0)
		return dp[i];
	dp[i]=0;
	ll x1=-1,x2=-1;
	if(i-a[i]>=1)
		x1=a[i-a[i]];
	if(i+a[i]<=n)
		x2=a[i+a[i]];
	if(diff_parity(x1, a[i]) || diff_parity(x2, a[i]))
	{
		dp[i]=1;
		return dp[i];
	}
	if(x1!=-1 && dp[i-a[i]]==-1)
		x1=rec(i-a[i]);
	if(x2!=-1 && dp[i+a[i]]==-1)
		x2=rec(i+a[i]);
	if(x1!=-1)
		dp[i]=x1;
	if(x2!=-1)
	{
		if(dp[i]!=0)
			dp[i]=min(dp[i], x2);
		else
			dp[i]=x2;
	}
	return dp[i];

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i;
	a.pb(-1);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=1;i<=n;i++)
	{
		ll tmp=rec(i);
		if(tmp==0)
			tmp--;
		cout<<tmp<<" ";
	}
	cout<<endl;
	return 0;
}