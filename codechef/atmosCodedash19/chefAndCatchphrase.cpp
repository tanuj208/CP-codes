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
ll dp[5005][5005]; // length i+1 and number of vowels j

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll i,j;
	ll c=0,v=0;
	for(i=0;i<sz(s);i++)
	{
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
			v++;
		else
			c++;
	}
	// cout<<c<<" "<<v<<endl;
	dp[0][0] = c;
	dp[0][1] = v;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			ll vowels = j;
			ll consonants = i-j;
			if(vowels > consonants)
				continue;
			dp[i][vowels+1] += ((v-vowels)*dp[i-1][vowels])%mod;
			dp[i][vowels] += ((c-consonants)*dp[i-1][vowels])%mod;
			dp[i][vowels+1]%=mod;
			dp[i][vowels]%=mod;
		}
	}
	ll ans=0;
	for(j=0;j<=n;j++)
	{
		ll vowels = j;
		ll consonants = n-j;
		if(vowels>consonants)
			continue;
		ans+=dp[n-1][j];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}