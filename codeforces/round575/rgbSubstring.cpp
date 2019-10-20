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

vector<ll> func(char aa, char bb, char cc, string s)
{
	ll i;
	vector<ll> a;
	for(i=0;i<sz(s);i++)
	{
		if(i%3==0)
		{
			if(s[i]!=aa)
				a.pb(1);
			else
				a.pb(0);
		}
		else if(i%3==1)
		{
			if(s[i]!=bb)
				a.pb(1);
			else
				a.pb(0);
		}
		else
		{
			if(s[i]!=cc)
				a.pb(1);
			else
				a.pb(0);
		}
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		ll i;
		vector<ll> a[3];
		a[0]=func('R', 'G', 'B', s);
		a[1]=func('G', 'B', 'R', s);
		a[2]=func('B', 'R', 'G', s);
		ll aa=0,bb=0,cc=0;
		ll ans=LLONG_MAX;
		for(i=0;i<k;i++)
		{
			aa+=a[0][i];
			bb+=a[1][i];
			cc+=a[2][i];
		}
		ans=min(ans, min(aa, min(bb, cc)));
		for(i=k;i<n;i++)
		{
			aa+=a[0][i]-a[0][i-k];
			bb+=a[1][i]-a[1][i-k];
			cc+=a[2][i]-a[2][i-k];
			ans=min(ans, min(aa, min(bb, cc)));
		}
		cout<<ans<<endl;
	}
	return 0;
}