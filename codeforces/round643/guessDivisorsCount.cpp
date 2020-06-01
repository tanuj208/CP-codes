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

ll q(ll Q)
{
	cout<<"? "<<Q<<endl;
	fflush(stdout);
	ll g;
	cin>>g;
	return g;
}

ll get_power(ll a, ll b)
{
	ll cnt=0;
	while(a%b==0)
	{
		cnt++;
		a/=b;
	}
	return cnt;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll t;
	cin>>t;
	vector<ll> p;
	ll cnt=0;
	ll i,j;
	for(i=2;i<=200;i++)
	{
		bool flag = true;
		for(j=2;j<=i-1;j++)
		{
			if(i%j==0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cnt++;
			p.pb(i);
			if(cnt == 44)
				break;
		}
	}
	vector<ll> pr = p;
	for(i=0;i<44;i++)
	{
		ll x = p[i];
		while(p[i] < 1e9/x)
			p[i]*=x;
	}
	while(t--)
	{
		ll ans = 1;
		for(i=0;i<44;i+=2)
		{
			ll x = q(p[i]*p[i+1]);
			ans *= (get_power(x, pr[i]) + 1);
			ans *= (get_power(x, pr[i+1]) + 1);
		}
		ans = max(2*ans, ans+7);
		cout<<"! "<<ans<<endl;
		fflush(stdout);
	}
	return 0;
}