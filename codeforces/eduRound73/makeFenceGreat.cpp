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

void fill(ll i, vector<ll>& a, vector<ll>& b, vector<vector<ll>>& dp)
{
	ll zt = min(dp[i-1][0], dp[i-1][2]);
	ll zo = min(dp[i-1][0], dp[i-1][1]);
	ll ot = min(dp[i-1][1], dp[i-1][2]);
	ll al=min(dp[i-1][1], min(dp[i-1][0], dp[i-1][2]));
	if(a[i]==a[i-1])
	{
		dp[i][0]=ot;
		dp[i][1]=b[i]+zt;
		dp[i][2]=2*b[i]+zo;
	}
	else if(a[i]==a[i-1]+1)
	{
		dp[i][0]=zt;
		dp[i][1]=b[i]+zo;
		dp[i][2]=2*b[i]+al;
	}
	else if(a[i]==a[i-1]+2)
	{
		dp[i][0]=zo;
		dp[i][1]=b[i]+al;
		dp[i][2]=2*b[i]+al;
	}
	else if(a[i]==a[i-1]-1)
	{
		dp[i][0]=al;
		dp[i][1]=b[i]+ot;
		dp[i][2]=2*b[i]+zt;
	}
	else if(a[i]==a[i-1]-2)
	{
		dp[i][0]=al;
		dp[i][1]=b[i]+al;
		dp[i][2]=2*b[i]+ot;
	}
	else
	{
		dp[i][0]=al;
		dp[i][1]=b[i]+al;
		dp[i][2]=2*b[i]+al;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		vector<vector<ll>> dp(n+5, vector<ll> (3, -1));
		vector<ll> a,b;
		ll i;
		for(i=0;i<n;i++)
		{
			ll aa,bb;
			cin>>aa>>bb;
			a.pb(aa);
			b.pb(bb);
		}
		dp[0][0]=0;
		dp[0][1]=b[0];
		dp[0][2]=2*b[0];
		for(i=1;i<n;i++)
			fill(i, a, b, dp);
		cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]))<<endl;
	}
	return 0;
}