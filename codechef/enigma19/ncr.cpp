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
		ll k;
		cin>>k;
		ll i;
		vector<ll> a;
		bool even=false;
		for(i=0;i<k;i++)
		{
			ll val;
			cin>>val;
			if(val%2==0)
				even=true;
			a.pb(val);
		}
		if(k%2==0)
			cout<<0<<endl;
		else if(even)
			cout<<1<<endl;
		else
		{
			ll ans=LLONG_MAX;
			for(i=0;i<k;i++)
			{
				ll x=a[i];
				ll tmp=1;
				bool flag=false;
				while(a[i]!=0)
				{
					if(a[i]%2==0)
					{
						flag=true;
						break;
					}
					tmp*=2;
					a[i]/=2;
				}
				if(flag)
					ans=min(ans,tmp);
			}
			if(ans==LLONG_MAX)
				cout<<-1<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}