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
		ll n,m;
		cin>>n>>m;
		vector<ll> sizes(50,0);
		ll i;
		for(i=0;i<m;i++)
		{
			ll val;
			cin>>val;
			ll cnt=-1;
			while(val!=0)
			{
				cnt++;
				val/=2;
			}
			// cout<<cnt<<endl;
			sizes[cnt]++;
		}
		vector<ll> cum(50, 0);
		for(i=0;i<45;i++)
		{
			if(i==0)
				cum[i]=sizes[i];
			else
				cum[i]=cum[i-1] + sizes[i]*((ll)1<<i);
		}
		ll ans=0;
		while(n!=0)
		{
			for(i=0;i<45;i++)
			{
				if(cum[i]>=n)
					break;
			}
			if(i==45)
			{
				ans=-1;
				break;
			}
			ll x=(ll)1<<i;
			if(x>n)
			{
				ans++;
				cum[i]-=x;
				cum[i-1]+=x;
			}
			else
			{
				n-=x;
				cum[i]-=x;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}