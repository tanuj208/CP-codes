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

char anyOther(char a)
{
	if(a=='R')
		return 'G';
	else
		return 'R';
}

char other(char a, char b)
{
	string tmp="RGB";
	ll i;
	for(i=0;i<3;i++)
		if(tmp[i]!=a && tmp[i]!=b)
			return tmp[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	string s;
	cin>>n>>s;
	ll i;
	string ans="";
	ll cnt=0;
	ans+=s[0];
	for(i=1;i<n;i++)
	{
		if(s[i]==ans[i-1])
		{
			cnt++;
			if(i+1==n || s[i-1]==s[i+1])
				ans+=anyOther(s[i-1]);
			else
				ans+=other(s[i-1], s[i+1]);
		}
		else
			ans+=s[i];
	}
	cout<<cnt<<endl<<ans<<endl;
	return 0;
}