#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin() a.end()
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

ll v(string s)
{
	ll i;
	ll val=0;
	ll closed=0;
	for(i=0;i<sz(s);i++)
	{
		if(val>0)
		{
			closed+=val;
			val=0;
		}
		if(s[i]=='(')
			val--;
		else
			val++;
	}
	if(val>0)
	{
		closed+=val;
		val=0;
	}
	if(closed>0 && val<0)
		return LLONG_MAX;
	else if(val<0)
		return val;
	else
		return closed;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<ll> cnt(1000000,0);
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(v(s)==LLONG_MAX)
			continue;
		// cout<<v(s)<<endl;
		cnt[v(s)+500000]++;
	}
	ll ans=0;
	for(i=1;i<=500000;i++)
	{
		if(cnt[i]>0 && cnt[1000000-i]>0)
		{
			if(i==1000000-i)
				ans+=(cnt[i]/2);
			else
				ans+=min(cnt[i],cnt[1000000-i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}