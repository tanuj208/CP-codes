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

typedef int ll;
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
		ll n;
		cin>>n;
		vector<vector<ll>> cnt(n+5, vector<ll> (205));
		ll i,j;
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		vector<ll> hsh(300, 0);
		for(i=n-1;i>=0;i--)
		{
			hsh[a[i]]++;
			cnt[i]=hsh;
		}
		vector<vector<ll>> cnt2(300);
		for(i=n-1;i>=0;i--)
			cnt2[a[i]].pb(i);
		ll ans=1;
		vector<ll> hshh(300, 0);
		for(i=0;i<n;i++)
		{
			ll cur_no = a[i];
			hshh[cur_no]++;
			ll occ = hshh[cur_no];
			ll oth_idx = cnt2[cur_no][occ-1];
			if(oth_idx <= i)
				continue;
			else
			{
				ll mx=0;
				for(j=0;j<=200;j++)
				{
					ll xx = -cnt[oth_idx][j] + cnt[i][j];
					if(j==cur_no)
						xx--;
					mx=max(mx, xx);
				}
				ans = max(ans, 2*occ + mx);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}