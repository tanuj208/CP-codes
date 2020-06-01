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
	vector<ll> ps;
	vector<bool> prime(1005, true);
	ll i,j;
	for(i=2;i<=1000;i++)
	{
		if(!prime[i])
			continue;
		for(j=2*i;j<=1000;j+=i)
			prime[j]=false;
	}
	for(i=2;i<=31;i++)
		if(prime[i])
			ps.pb(i);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		vector<ll> col(n+2, -1);
		ll c=1;
		for(i=0;i<sz(ps);i++)
		{
			bool flag=false;
			for(j=0;j<n;j++)
			{
				if(col[j]!=-1)
					continue;
				if(a[j]%ps[i] == 0)
				{
					col[j]=c;
					flag=true;
				}
			}
			if(flag)
				c++;
		}
		cout<<c-1<<endl;
		for(i=0;i<n;i++)
			cout<<col[i]<<" ";
		cout<<endl;
	}
	return 0;
}