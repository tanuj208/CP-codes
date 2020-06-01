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
	ll q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		ll l=0,r=0,u=0,d=0;
		ll i;
		for(i=0;i<sz(s);i++)
		{
			if(s[i]=='U')
				u++;
			else if(s[i]=='D')
				d++;
			else if(s[i]=='R')
				r++;
			else
				l++;
		}
		ll x1=min(r,l);
		ll x2=min(u,d);
		if(x1==0 && x2==0)
		{
			cout<<0<<endl<<endl;
			continue;
		}
		if(x2==0)
			x1=1;
		if(x1==0)
			x2=1;
		cout<<2*x1+2*x2<<endl;
		for(i=0;i<x1;i++)
			cout<<'R';
		for(i=0;i<x2;i++)
			cout<<'U';
		for(i=0;i<x1;i++)
			cout<<'L';
		for(i=0;i<x2;i++)
			cout<<'D';
		cout<<endl;
	}
	return 0;
}