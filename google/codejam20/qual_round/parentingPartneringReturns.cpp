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
	for(ll z=1 ; z<=t ; z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n;
		cin>>n;
		vector<pair<pii,ll>> act;
		ll i;
		for(i=0;i<n;i++)
		{
			ll l,r;
			cin>>l>>r;
			act.pb(mp(mp(l,r), i));
		}
		sort(all(act));
		vector<char> ans(n+2);
		ll rc=-1, rj=-1;
		bool pos = true;
		for(i=0;i<n;i++)
		{
			ll l = act[i].ff.ff;
			ll r = act[i].ff.ss;
			ll idx = act[i].ss;

			if(l >= rc)
			{
				rc = r;
				ans[idx] = 'C';
			}
			else if(l >= rj)
			{
				rj = r;
				ans[idx] = 'J';
			}
			else
			{
				pos=false;
				break;
			}
		}
		if(!pos)
			cout<<"IMPOSSIBLE"<<endl;
		else
		{
			for(i=0;i<n;i++)
				cout<<ans[i];
			cout<<endl;
		}
	}
	return 0;
}