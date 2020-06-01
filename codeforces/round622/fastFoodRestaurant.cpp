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

void one(ll &a, ll &ans)
{
	if(a!=0)
	{
		a--;
		ans++;
	}
}

void two(ll &a, ll& b, ll& ans)
{
	if(a!=0 && b!=0)
	{
		a--;
		b--;
		ans++;
	}
}

void aall(ll& a, ll& b, ll& c, ll& ans)
{
	if(a==0 || b==0 || c==0)
		return;
	a--;
	b--;
	c--;
	ans++;
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
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans=0;
		one(a, ans);
		one(b, ans);
		one(c, ans);
		ll mx=max(a,max(b,c));
		if(mx==a)
		{
			two(a,b,ans);
			two(a,c,ans);
			two(b,c,ans);
		}
		else if(mx==b)
		{
			two(a,b,ans);
			two(b,c,ans);
			two(a,c,ans);
		}
		else
		{
			two(a,c,ans);
			two(b,c,ans);
			two(a,b,ans);
		}
		aall(a,b,c,ans);
		cout<<ans<<endl;
	}
	return 0;
}