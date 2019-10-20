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
	ll a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	ll pl1=0,pl2=0;
	ll bka1 = a1, bka2 = a2, bkn = n;
	while(n>=k1 && a1>=1)
	{
		n-=k1;
		a1--;
		pl1++;
	}
	while(n>=k2 && a2>=1)
	{
		n-=k2;
		a2--;
		pl1++;
	}
	a1=bka1, a2=bka2, n=bkn;
	while(n>=k2 && a2>=1)
	{
		n-=k2;
		a2--;
		pl2++;
	}
	while(n>=k1 && a1>=1)
	{
		n-=k1;
		a1--;
		pl2++;
	}
	a1=bka1, a2=bka2, n=bkn;
	ll nn = a1*(k1-1) + a2*(k2-1);
	ll minPl = min(n-nn, a1+a2);
	cout<<max(minPl, (ll)0)<<" "<<max(pl1, pl2)<<endl;
	return 0;
}