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
	ll k,i;
	cin>>k;
	bool ans=false;
	for(i=5;i<k;i++)
	{
		if(k%i==0)
		{
			ll x=k/i;
			if(x>=5)
			{
				ans=true;
				break;
			}
		}
	}
	if(!ans)
	{
		cout<<-1<<endl;
		return 0;
	}
	ll x1=i;
	ll x2=k/i;
	// cout<<x1<<" "<<x2<<endl;
	while(x1>0)
	{
		cout<<"aeiou";
		for(i=0;i<x2-5;i++)
			cout<<"a";
		x1--;
		if(x1==0)
			break;

		cout<<"eioua";
		for(i=0;i<x2-5;i++)
			cout<<"e";
		x1--;
		if(x1==0)
			break;

		cout<<"iouae";
		for(i=0;i<x2-5;i++)
			cout<<"i";
		x1--;
		if(x1==0)
			break;

		cout<<"ouaei";
		for(i=0;i<x2-5;i++)
			cout<<"o";
		x1--;
		if(x1==0)
			break;

		cout<<"uaeio";
		for(i=0;i<x2-5;i++)
			cout<<"u";
		x1--;
		if(x1==0)
			break;
	}
	cout<<endl;

	return 0;
}