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
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll sum1=0, sum2=0;
	ll q1=0, q2=0;
	ll i;
	for(i=0;i<n/2;i++)
	{
		if(s[i]=='?')
			q1++;
		else
			sum1+=(s[i]-'0');
	}
	for(i=n/2;i<n;i++)
	{
		if(s[i]=='?')
			q2++;
		else
			sum2+=(s[i]-'0');
	}
	if(q1>=q2)
	{
		ll x=(q1-q2)/2;
		if(sum2-sum1 == 9*x)
			cout<<"Bicarp\n";
		else
			cout<<"Monocarp\n";
	}
	else
	{
		ll x=(q2-q1)/2;
		if(sum1-sum2 == 9*x)
			cout<<"Bicarp\n";
		else
			cout<<"Monocarp\n";
	}
	return 0;
}