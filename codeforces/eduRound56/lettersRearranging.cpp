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
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n=sz(s);
		ll i;
		bool flag=true;
		for(i=1;i<n;i++)
		{
			if(s[i]!=s[i-1])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"-1\n";
			continue;
		}
		flag=true;
		for(i=0;i<n;i++)
		{
			if(s[i]!=s[n-i-1])
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			cout<<s<<"\n";
			continue;
		}
		for(i=1;i<n;i++)
		{
			if(s[i]==s[i-1])
				cout<<s[i-1];
			else
			{
				cout<<s[i]<<s[i-1];
				break;
			}
		}
		for(i=i+1;i<n;i++)
			cout<<s[i];
		cout<<"\n";
	}
	return 0;
}