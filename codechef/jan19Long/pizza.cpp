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

ll ccase(ll x,ll y,ll z)
{
	if(y==x+1 && z==y+1)
		return 1;
	else if(y==x+1 && z==y-1)
		return 2;
	else if(y==x-1 && z==y+1)
		return 3;
	else
		return 4;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,t,x,y,z;
		cin>>n>>t>>x>>y>>z;
		ll c=ccase(x,y,z);
		ll num,den;
		den=2*n+1;
		if(t==1 && c==1)
			num=den-2-x;
		else if((t==1 || t==3) && (c==2 || c==3))
			num=x;
		else if(t==1 && c==4)
			num=den+2-x;
		else if((t==2 || t==4) && (c==2 || c==3))
			num=0;
		else if((t==3 && c==1) || (t==3 && c==4))
			num=den-x;
		else if(t==4 && c==1 || (t==2 && c==1))
			num=den-2-2*x;
		else if((t==4 && c==4) || (t==2 && c==4))
			num=den+2-2*x;
	
		if(num==0)
			cout<<0<<" "<<1<<"\n";
		else
		{
			ll gcd=__gcd(num,den);
			cout<<num/gcd<<" "<<den/gcd<<"\n";
		}
	}
	return 0;
}