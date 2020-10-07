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

vector<pii> get_p(ll x, ll y)
{
	ll i;
	vector<pii> tmp;
	if(x==1)
		return tmp;
	ll j=1;
	while(true)
	{
		if(1+j > x)
			break;
		for(i=1;i<=x;i+=j*2)
		{
			for(ll k=i;k<i+j;k++)
			{
				if(i+j <= x)
					tmp.pb(mp(y+k, y+k+j));
			}
		}
		j*=2;
	}
	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	ll backup;
	cin>>n;
	backup = n;
	if(n==1)
	{
		cout<<0<<endl<<endl;
		return 0;
	}
	if(n==2 || n == 3)
	{
		cout<<1<<endl<<1<<" "<<2<<endl;
		return 0;
	}
	ll x = 1;
	for(i=0;i<100;i++)
	{
		if(x > n)
			break;
		x*=2;
	}
	x/=2;
	vector<pii> ans = get_p(x, 0);
	n-=x;
	x=1;
	for(i=0;i<100;i++)
	{
		if(x>=n)
			break;
		x*=2;
	}
	vector<pii> ans2 = get_p(x, backup-x);
	cout<<sz(ans)+sz(ans2)<<endl;
	for(i=0;i<sz(ans);i++)
		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	for(i=0;i<sz(ans2);i++)
		cout<<ans2[i].ff<<" "<<ans2[i].ss<<endl;
	return 0;
}
