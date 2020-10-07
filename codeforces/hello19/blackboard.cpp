#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin() a.end()
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

map<ll,vector<ll> > x;

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

void divisors(ll q)
{
	ll i;
	vector<ll> tmp;
	if(q==1)
	{
		tmp.pb(1);
		x[1]=tmp;
		return;
	}
	for(i=1;i<=sqrt(q);i++)
	{
		if(q%i==0)
		{
			ll qq=q/i;
			tmp.pb(i);
			if(x.find(i)==x.end())
				divisors(i);
			if(q!=qq)
			{
				tmp.pb(qq);
				if(x.find(qq)==x.end() && qq!=q)
					divisors(qq);
			}
		}
	}
	x[q]=tmp;
	// if(q==33)
	// cerr<<"DFLJ"<<endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n;
	divisors(n);
	// cout<<x[1][0]<<endl;
	return 0;
}