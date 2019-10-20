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
	string s,t;
	cin>>s>>t;
	ll i;
	vector<ll> ab,ba,aa,bb;
	for(i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			if(t[i]=='b')
				ab.pb(i);
			else
				aa.pb(i);
		}
		else
		{
			if(t[i]=='b')
				bb.pb(i);
			else
				ba.pb(i);
		}
	}
	vector<pii> ans;
	for(i=1;i<sz(ab);i+=2)
	{
		ll i1=ab[i-1];
		ll i2=ab[i];
		ans.pb(mp(i1, i2));
		aa.pb(i2);
		bb.pb(i1);
	}
	for(i=1;i<sz(ba);i+=2)
	{
		ll i1=ba[i-1];
		ll i2=ba[i];
		ans.pb(mp(i1, i2));
		aa.pb(i1);
		bb.pb(i2);
	}
	ll abCnt = sz(ab)%2;
	ll baCnt = sz(ba)%2;
	if((abCnt!=0 && baCnt==0) || (abCnt==0 && baCnt!=0))
		cout<<-1<<endl;
	else if(abCnt==0 && baCnt==0)
	{
		cout<<sz(ans)<<endl;
		for(i=0;i<sz(ans);i++)
			cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<endl;
	}
	else
	{
		ll i1=ab[sz(ab)-1];
		ll i2=ba[sz(ba)-1];
		ans.pb(mp(i1, i1));
		ans.pb(mp(i1, i2));
		cout<<sz(ans)<<endl;
		for(i=0;i<sz(ans);i++)
			cout<<1+ans[i].ff<<" "<<1+ans[i].ss<<endl;
	}
	return 0;
}