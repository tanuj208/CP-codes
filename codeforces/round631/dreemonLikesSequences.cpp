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
	ll t;
	cin>>t;
	while(t--)
	{
		ll d,m;
		cin>>d>>m;
		vector<ll> cnt(35,0);
		ll cur=2;
		ll cntr=1;
		while(true)
		{
			if(cur-1 <= d)
			{
				cnt[cntr] = cur/2;
				cur*=2;
				cntr++;
			}
			else
			{
				cnt[cntr] = d - cur/2 + 1;
				break;
			}
		}
		ll i,j;
		for(i=1;i<=30;i++)
			cnt[i] = cnt[i] % m;
		// for(i=0;i<30;i++)
		// 	cout<<cnt[i]<<" ";
		// cout<<endl;
		vector<vector<ll>> dp(35, vector<ll> (35, 0));
		ll ans=0;
		for(j=1;j<=30;j++)
		{
			ans += cnt[j];
			ans %= m;
			dp[1][j] = cnt[j];
			dp[1][j] %= m;
		}
		for(i=2;i<=30;i++)
		{
			for(j=1;j<=30;j++)
			{
				ll k;
				ll s=0;
				for(k=j+1;k<=30;k++)
				{
					s+=dp[i-1][k];
					s %= m;
				}
				dp[i][j] = cnt[j] * s;
				dp[i][j] %= m;
				ans += dp[i][j];
				ans %= m;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}