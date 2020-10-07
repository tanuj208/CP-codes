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

ll query(vector<ll> a, vector<ll> b)
{
	ll i;
	cout<<sz(a)<<" "<<sz(b)<<" ";
	for(i=0;i<sz(a);i++)
		cout<<a[i]<<" ";
	for(i=0;i<sz(b);i++)
		cout<<b[i]<<" ";
	cout<<endl;
	fflush(stdout);
	ll xx;
	cin>>xx;
	return xx;
}

ll numberOfBits(ll x)
{
	ll cnt=0;
	while(x!=0)
		x/=2,cnt++;
	return cnt;
}

bool bitVal(ll x, ll ind)
{
	ll cnt=0;
	while(x!=0)
	{
		if(x%2==1 && cnt==ind)
			return true;
		else if(cnt==ind)
			return false;
		x/=2;
		cnt++;
	}
	return false;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll t,i;
	cin>>t;
	bool flag=false;
	while(t--)
	{
		ll n;
		cin>>n;
		ll j;
		ll ans=0;
		ll cnt=numberOfBits(n);
		for(j=0;j<cnt;j++)
		{
			vector<ll> a,b;
			for(i=1;i<=n;i++)
			{
				if(bitVal(i, j))
					a.pb(i);
				else
					b.pb(i);
			}
			ll xx=query(a,b);
			if(xx==-1)
			{
				flag = true;
				break;
			}
			ans=max(ans, xx);
		}
		if(flag)
			break;
		cout<<"-1 "<<ans<<endl;
		fflush(stdout);
	}
	return 0;
}