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

map<ll,pii> x;


pii query(ll i,ll j)
{
	cout<<"? "<<i<<" "<<j<<endl;
	fflush(stdout);
	ll xx;
	cin>>xx;
	return x[xx];
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	vector<ll> a;
	a.pb(4);
	a.pb(8);
	a.pb(15);
	a.pb(16);
	a.pb(23);
	a.pb(42);
	ll i,j;
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			if(i!=j)
				x[a[i]*a[j]]=mp(a[i], a[j]);

	vector<ll> ans(6);
	pii x1 = query(1,2);
	pii x2 = query(2,3);
	if(x1.first==x2.first)
	{
		ans[0]=x1.second;
		ans[1]=x1.first;
		ans[2]=x2.second;
	}
	else if(x1.first==x2.second)
	{
		ans[0]=x1.second;
		ans[1]=x1.first;
		ans[2]=x2.first;
	}
	else if(x1.second==x2.first)
	{
		ans[0]=x1.first;
		ans[1]=x1.second;
		ans[2]=x2.second;
	}
	else
	{
		ans[0]=x1.first;
		ans[1]=x1.second;
		ans[2]=x2.first;
	}

	x1 = query(4,5);
	x2 = query(5,6);
	if(x1.first==x2.first)
	{
		ans[3]=x1.second;
		ans[4]=x1.first;
		ans[5]=x2.second;
	}
	else if(x1.first==x2.second)
	{
		ans[3]=x1.second;
		ans[4]=x1.first;
		ans[5]=x2.first;
	}
	else if(x1.second==x2.first)
	{
		ans[3]=x1.first;
		ans[4]=x1.second;
		ans[5]=x2.second;
	}
	else
	{
		ans[3]=x1.first;
		ans[4]=x1.second;
		ans[5]=x2.first;
	}

	cout<<"! ";
	for(i=0;i<6;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	fflush(stdout);
	return 0;
}