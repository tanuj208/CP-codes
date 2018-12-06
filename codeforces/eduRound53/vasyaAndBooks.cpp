#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

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
	stack<ll> s;
	ll i;
	ll n;
	cin>>n;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=n-1;i>=0;i--)
		s.push(a[i]);
	vector<ll> done(200005,0);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		if(done[val]==1)
		{
			cout<<"0 ";
		}
		else
		{
			ll cnt=0;
			ll x=s.top();
			while(x!=val)
			{
				done[x]=1;
				cnt++;
				s.pop();
				x=s.top();
			}
			s.pop();
			done[x]=1;
			cnt++;
			cout<<cnt<<" ";
		}
	}
	cout<<endl;
	return 0;
}