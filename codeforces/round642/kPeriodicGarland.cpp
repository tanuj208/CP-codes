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

vector<ll> oneCnt(1000005, 0);
vector<ll> dp(1000005, -1);
ll n,k;
string s;

ll rec(ll idx)
{
	if(dp[idx] != -1)
		return dp[idx];
	ll xx = oneCnt[n-1] - oneCnt[idx];
	if(s[idx]=='1')
		xx++;
	if(xx==0)
	{
		dp[idx]=0;
		return dp[idx];
	}
	ll cnt=0;
	if(s[idx] == '0')
		cnt++;
	if(idx+k < n)
	{
		cnt += rec(idx+k);
		cnt += oneCnt[idx+k-1]-oneCnt[idx];
	}
	else
		cnt += oneCnt[n-1]-oneCnt[idx];
	dp[idx]=min(cnt, xx);
	return dp[idx];
}

void reset()
{
	for(ll i=0;i<=n;i++)
	{
		oneCnt[i]=0;
		dp[i]=-1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		reset();
		cin>>s;
		ll i;
		if(s[0]=='1')
			oneCnt[0]=1;
		for(i=1;i<n;i++)
		{
			oneCnt[i]=oneCnt[i-1];
			if(s[i]=='1')
				oneCnt[i]++;
		}
		if(oneCnt[n-1] <= 1)
		{
			cout<<0<<endl;
			continue;
		}
		ll ans=oneCnt[n-1]-1;
		for(i=0;i<n;i++)
		{
			ll x1 = rec(i);
			ll ocnt = 0;
			if(i!=0)
				ocnt=oneCnt[i-1];
			// cout<<i<<" "<<ocnt<<" "<<x1<<endl;
			ans = min(ans, ocnt+x1);
		}
		cout<<ans<<endl;
	}
	return 0;
}