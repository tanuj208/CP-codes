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
string ori;

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

bool isValid(string s)
{
	ll i;
	ll n = sz(s);
	for(i=0;i<n;i++)
		if(s[i]!=s[n-i-1])
			return false;
	if(s!=ori)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ori = s;
	ll i;
	bool flag = true;
	for(i=1;i<sz(s);i++)
	{
		if(sz(s)%2==1 && (i == sz(s)/2 || i == sz(s)/2+1))
			continue;
		if(s[i]!=s[i-1])
		{
			flag = false;
			break;
		}
	}
	if(flag)
		cout<<"Impossible\n";
	else
	{
		for(i=0;i<sz(s)-1;i++)
		{
			rotate(s.begin(),s.begin()+1,s.end());
			if(isValid(s))
			{
				flag = true;
				break;
			}
		}
		if(flag)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
	return 0;
}