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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	while(true)
	{
		string s;
		cin>>s;
		bool wrong = false;
		if(s=="end" || s=="mistake" || wrong)
			break;
		ll a1=1;
		ll a2=2;
		while(true)
		{
			cout<<"? "<<a1<<" "<<a2<<endl;
			fflush(stdout);
			string ss;
			cin>>ss;
			if(ss=="x")
				break;
			a1*=2;
			a2*=2;
		}
		ll l=a1;
		ll r=a2;
		cout<<"? 0 "<<a1<<endl;
		fflush(stdout);
		string tmp;
		cin>>tmp;
		if(tmp=="x")
		{
			cout<<"! "<<a1<<endl;
			fflush(stdout);
			continue;
		}
		ll mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(r==l+1)
			{
				cout<<"! "<<r<<endl;
				break;
			}
			cout<<"? "<<l<<" "<<mid<<endl;
			fflush(stdout);
			string s1;
			cin>>s1;
			if(s1=="e")
			{
				wrong=true;
				break;
			}
			if(s1=="x")
				r=mid;
			else
				l=mid;
		}
		if(wrong)
			break;
		fflush(stdout);
	}
	return 0;
}