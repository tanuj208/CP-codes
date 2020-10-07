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
	ll n;
	cin>>n;
	ll curh1=0;
	ll curw1=0;
	ll curh2=0;
	ll curw2=0;
	while(n--)
	{
		char c;
		cin>>c;
		if(c=='+')
		{
			ll x,y;
			cin>>x>>y;
			ll h1=max(curh1,x);
			ll w1=max(curw1,y);
			ll h2=max(curh1,y);
			ll w2=max(curw1,x);
			if(h1<h2 || (h1==h2 && w1<=w2))
				curh1=h1,curw1=w1;
			else
				curh1=h2,curw1=w2;
			ll h3=max(curh2,x);
			ll w3=max(curw2,y);
			ll h4=max(curh2,y);
			ll w4=max(curw2,x);
			if(w3<w4 || (w3==w4 && h3<=h4))
				curh2=h3,curw2=w3;
			else
				curh2=h4,curw2=w4;
		}
		else
		{
			ll h,w;
			cin>>h>>w;
			if((h>=curh1 && w>=curw1) || (h>=curh2 && w>=curw2))
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}