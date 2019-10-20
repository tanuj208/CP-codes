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
	ll curMax = 0;
	while(t--)
	{
		ll n,x;
		cin>>n>>x;
		ll i;
		set<pii, greater<pii>> x1;
		vector<pii> x2;
		ll cur=0;
		for(i=0;i<n;i++)
		{
			ll d,h;
			cin>>d>>h;
			if(h>=d)
			{
				curMax = max(curMax, d);
				continue;
			}
			x1.insert(mp(d, cur));
			x2.pb(mp(d-h, d));
			cur++;
		}
		if(cur==0)
		{
			if(curMax >= x)
				cout<<1<<endl;
			else
				cout<<-1<<endl;
			continue;
		}
		sort(all(x2));
		ll mxBlow = x1.begin()->ff;
		if(mxBlow>=x)
		{
			cout<<1<<endl;
			continue;
		}
		ll cnt=0;
		bool done=false;
		for(i=0;i<sz(x2);i++)
		{
			cnt++;
			x-=x2[i].ff;
			x1.erase(mp(x2[i].ss, i));
			if(curMax>=x)
			{
				cout<<cnt<<endl;
				done = true;
				break;
			}
			else if(sz(x1) != 0 && x1.begin()->ff >= x)
			{
				cout<<cnt+1<<endl;
				done = true;
				break;
			}
		}
		if(!done)
			cout<<-1<<endl;
	}
	return 0;
}