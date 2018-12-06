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

ll ddone=0,fdone=0,jdone=0,kdone=0;

ll func(string s)
{
	ll left=0;
	if(s[0]=='d' || s[0]=='f')
		left=1;
	ll ans=2;
	ll i;
	for(i=1;i<sz(s);i++)
	{
		ll x;
		if(s[i]=='d')
		{
			if(left==0)
				ans+=2;
			else
				ans+=4;
			left=1;
		}
		else if(s[i]=='f')
		{
			if(left==0)
				ans+=2;
			else
				ans+=4;
			left=1;
		}
		else if(s[i]=='j')
		{
			if(left==1)
				ans+=2;
			else
				ans+=4;
			left=0;
		}
		else if(s[i]=='k')
		{
			if(left==1)
				ans+=2;
			else
				ans+=4;
			left=0;
		}
	}
	return ans;
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
		ll n;
		cin>>n;
		ll i;
		ll ans=0;
		map<string,ll> x;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			if(x.find(s)!=x.end())
				ans+=x[s]/2;
			else
			{
				x[s]=func(s);
				ans+=x[s];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}