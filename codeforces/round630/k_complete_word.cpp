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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll x=n/k;
		ll i,j;
		ll ans=0;
		for(i=0;i<k/2;i++)
		{
			vector<ll> cnt(26, 0);
			for(j=0;j<x;j++)
			{
				char c1 = s[k*j+i];
				char c2 = s[k*j+k-1-i];
				cnt[c1-'a']++;
				cnt[c2-'a']++;
			}
			ll tmp=0;
			for(j=0;j<26;j++)
				tmp = max(tmp, cnt[j]);
			ans = ans + (2*x-tmp);
		}
		if(k%2==1)
		{
			ll tmp=k/2;
			vector<ll> cnt(26, 0);
			for(j=0;j<x;j++)
				cnt[s[k*j+tmp]-'a']++;
			ll tmp2=0;
			for(j=0;j<26;j++)
				tmp2 = max(tmp2, cnt[j]);
			ans = ans + (x-tmp2);
		}
		cout<<ans<<endl;
	}
	return 0;
}