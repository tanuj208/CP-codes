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
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n=sz(s);
		ll i;
		set<ll> hash;
		for(i=0;i<n-4;i++)
			if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o' && s[i+3]=='n' && s[i+4]=='e')
				hash.insert(i+3);
		for(i=0;i<n-2;i++)
		{
			if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
			{
				if(hash.find(i+1)!=hash.end())
					continue;
				hash.insert(i+2);
			}
		}
		for(i=n-1;i>=2;i--)
		{
			if(s[i]=='o' && s[i-1]=='w' && s[i-2]=='t')
			{
				if(hash.find(i+1)!=hash.end())
					continue;
				hash.insert(i);
			}
		}
		cout<<sz(hash)<<endl;
		for(auto it=hash.begin();it!=hash.end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}