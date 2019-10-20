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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll i;
	ll ans=0;
	for(i=0;i<sz(s);i++)
	{
		if(ans==0)
		{
			if(s[i]!='[')
				continue;
			else
				ans++;
		}
		if(ans==1)
		{
			if(s[i]!=':')
				continue;
			else
			{
				ans++;
				break;
			}
		}
	}
	if(ans!=2)
	{
		cout<<-1<<endl;
		return 0;
	}
	ll cur1=i;
	for(i=sz(s)-1;i>=0;i--)
	{
		if(ans==2)
		{
			if(s[i]==']')
				ans++;
			else
				continue;
		}
		if(ans==3)
		{
			if(s[i]==':')
			{
				ans++;
				break;
			}
			else
				continue;
		}
	}
	ll cur2=i;
	if(ans!=4 || cur2<=cur1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(i=cur1+1;i<cur2;i++)
		if(s[i]=='|')
			ans++;
	cout<<ans<<endl;
	return 0;
}