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
		ll i;
		string s;
		cin>>s;
		ll ans=0;
		vector<ll> consZ;
		consZ.pb(0);
		ll cnt=0;
		for(i=0;i<sz(s);i++)
		{
			if(s[i]=='1')
				cnt=0;
			else
				cnt++;
			consZ.pb(cnt);
		}
		set<pii> v;
		ll pp[20];
		pp[0]=1;
		for(i=1;i<20;i++)
			pp[i]=2*pp[i-1];
		for(i=sz(s)-1;i>=0;i--)
		{
			ll j;
			if(s[i]=='1')
			{
				ans++;
				set<pii> tmp;
				for(auto it=v.begin();it!=v.end();it++)
				{
					ll x=it->ff;
					ll idx = it->ss;
					if(idx-i>=20)
						continue;
					ll newNo = x+pp[idx-i];
					if(newNo <= idx+1)
						tmp.insert(mp(newNo, idx));
					if(idx-i+1 <= newNo && idx-i+1+consZ[i] >= newNo)
						ans++;
				}
				v=tmp;
				v.insert(mp(1,i));
			}
			else
				v.insert(mp(0, i));
		}
		cout<<ans<<endl;
	}
	return 0;
}