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
ll r,c;

ll right_val(ll i, vector<ll>& s)
{
	if(i+1==c)
		return 0;
	else
		return s[i+1];
}

ll left_val(ll i, vector<ll>& s)
{
	if(i-1==-1)
		return 0;
	else
		return s[i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	ifstream inFile;
    inFile.open("balls.in");
	inFile>>t;
	while(t--)
	{
		inFile>>r>>c;
		vector<ll> b;
		ll i;
		for(i=0;i<c;i++)
		{
			ll val;
			inFile>>val;
			b.pb(val);
		}
		vector<vector<char>> grid(r+5, vector<char>(c+5));
		ll j;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				inFile>>grid[i][j];
		vector<ll> s;
		for(i=0;i<c;i++)
		{
			ll val;
			inFile>>val;
			s.pb(val);
		}
		vector<ll> dp(c+5, 0);
		for(i=r-1;i>=0;i--)
		{
			for(j=0;j<c;j++)
			{
				if(grid[i][j]=='.')
					dp[j]=s[j];
				else
					dp[j] = max(left_val(j, s), max(s[j], right_val(j, s)));
			}
			s=dp;
		}
		ll ans=0;
		for(i=0;i<c;i++)
			ans+=(s[i]*b[i]);
		cout<<ans<<endl;
	}
	return 0;
}