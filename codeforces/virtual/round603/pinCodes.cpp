#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
// #define mp make_pair
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

map<string,ll> mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		mp.clear();
		vector<string> ans;
		ans.clear();
		ll chn=0;
		ll i;
		vector<string> tt;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			tt.pb(s);
			mp[s]++;
		}
		for(i=0;i<n;i++)
		{
			string s=tt[i];
			if(mp[s]!=-1)
			{
				ans.pb(s);
				mp[s]=-1;
			}
			else
			{
				for(ll j=0;j<10;j++)
				{
					s[0]='0'+j;
					if(mp.find(s)==mp.end())
					{
						ans.pb(s);
						chn++;
						mp[s]=1;
						break;
					}
				}
			}
		}
		cout<<chn<<endl;
		for(i=0;i<sz(ans);i++)
			cout<<ans[i]<<endl;
	}
	return 0;
}