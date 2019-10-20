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
	ll n,k;
	cin>>n>>k;
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	vector<ll> consOnes(n+5, 0);
	if(a[n-1]==1)
		consOnes[n-1]=1;
	else
		consOnes[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		if(a[i]!=1)
			consOnes[i]=0;
		else
			consOnes[i]=1+consOnes[i+1];
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ll num=a[i];
		ll den=a[i];
		ll j;
		for(j=i+1;j<n;j++)
		{
			if(num==k*den)
				ans++;
			if(a[j]==1)
			{
				den+=consOnes[j];
				j+=consOnes[j];
			}
			else
			{
				num*=a[j];
				den+=a[j];
			}
			if(num > k*(den+1e5))
				break;
		}
		if(num==k*den)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}