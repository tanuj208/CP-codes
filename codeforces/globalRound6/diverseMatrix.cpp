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
	ll r,c;
	cin>>r>>c;
	if(r==1 && c==1)
	{
		cout<<0<<endl;
		return 0;
	}
	ll i,j;
	bool swapped=false;
	if(r>c)
	{
		swap(r,c);
		swapped=true;
	}
	ll mat[r+5][c+5];
	for(i=1;i<=r;i++)
	{

		for(j=1;j<=c;j++)
		{
			mat[i][j]=i*(r+j);
			// cout<<(i*(r+j))<<" ";
		}
		// cout<<endl;
	}
	if(swapped)
	{
		for(j=1;j<=c;j++)
		{
			for(i=1;i<=r;i++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
	else
	{
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
	// vector<ll> a;
	// for(i=1;i<=r;i++)
	// {
	// 	ll gcd=mat[i][1];
	// 	for(j=2;j<=c;j++)
	// 		gcd=__gcd(gcd, mat[i][j]);
	// 	a.pb(gcd);
	// }
	// for(j=1;j<=c;j++)
	// {
	// 	ll gcd=mat[1][j];
	// 	for(i=2;i<=r;i++)
	// 		gcd=__gcd(gcd, mat[i][j]);
	// 	a.pb(gcd);
	// }
	// ll mx=LLONG_MIN;
	// bool distinct=false;
	// map<ll,ll> xx;
	// for(i=0;i<sz(a);i++)
	// {
	// 	mx=max(mx, a[i]);
	// 	if(xx.find(a[i])!=xx.end())
	// 		cout<<a[i]<<" number is repeated\n";
	// 	xx[a[i]]=1;
	// }
	// cout<<mx<<endl;

	return 0;
}