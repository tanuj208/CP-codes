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

ll find_s(string a, string b, ll ind) // 0 not found, 1 found without asterisk, 2 found with asterisk
{
	if(sz(a)-ind < sz(b))
		return 0;
	ll i;
	bool flag = true;
	for(i=0;i<sz(b);i++)
	{
		if(a[ind]=='*')
		{
			ind++;
			flag = false;
			continue;
		}
		if(b[i]!=a[ind])
			return 0;
		ind++;
	}
	if(flag)
		return 1;
	else
		return 2;
}

string change(string a, string b, ll ind)
{
	ll i;
	for(i=0;i<sz(b);i++)
	{
		if(a[ind]=='*')
			a[ind]=b[i];
		ind++;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i;
	string c,s,t;
	cin>>c>>s>>t;
	ll ans=0;
	for(i=0;i<sz(s);i++)
	{
		if(find_s(c,s,i)==1)
			ans++;
		if(find_s(c,t,i)==1)
			ans--;
	}
	string original = c;

	for(i=0;i<sz(s);i++)
	{
		if(find_s(c,s,i)==2)
		{
			string tmp=change(c,s,i);
			ll cnt1=0;
			ll cnt2=0;
			for(ll j=i;j<i+sz(s);j++)
				if(find_s(tmp,s,j)==1 && find_s(c,s,j)==2)
					cnt1++;

			for(ll j=i;j<i+sz(s);j++)
				if(find_s(tmp,t,j)==1 && find_s(c,t,j)==2)
					cnt2++;
			if(cnt1>=cnt2)
			{
				ans+=cnt1-cnt2;
				c=tmp;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}