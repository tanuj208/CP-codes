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
	string s;
	cin>>s;
	ll i;
	ll n=sz(s);
	ll cnt=0;
	bool flag = true;
	bool flag2=true;
	string ans;
	ll ind;
	for(i=0;i<n;i++)
	{
		ans+=s[i];
		if(s[i]=='a')
		{
			if(cnt==n-i-1)
			{
				flag = false;
				i++;
				ind=i;
				while(i<n)
				{
					if(s[i]=='a')
					{
						cout<<":(\n";
						return 0;
					}
					i++;
				}
			}
			continue;
		}
		flag2=false;
		cnt++;
		if(cnt==n-i-1)
		{
			flag = false;
			i++;
			ind=i;
			while(i<n)
			{
				if(s[i]=='a')
				{
					cout<<":(\n";
					return 0;
				}
				i++;
			}
		}
	}
	if(flag2)
	{
		cout<<s<<endl;
		return 0;
	}
	if(flag)
	{
		cout<<":(\n";
		return 0;
	}
	ll j=ind;
	for(i=0;i<sz(ans);i++)
	{
		if(ans[i]=='a')
			continue;
		if(ans[i]!=s[j])
		{
			cout<<":(\n";
			return 0;
		}
		j++;
	}
	cout<<ans<<endl;
	return 0;
}