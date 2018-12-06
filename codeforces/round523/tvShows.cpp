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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,x,y;
	cin>>n>>x>>y;
	vector<pii> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val1,val2;
		cin>>val1>>val2;
		a.pb(mp(val1,val2));
	}
	sort(a.begin(),a.end());
	multiset<ll, greater<ll> > free;
	ll ans=0;
	multiset<ll> r;
	for(i=0;i<n;i++)
	{
		ll remCnt=0;
		for(auto it=r.begin();it!=r.end();it++)
		{
			if(*it>=a[i].first)
				break;
			free.insert(*it);
			remCnt++;
		}
		ll cnt=0;
		while(cnt!=remCnt)
		{
			r.erase(r.begin());
			cnt++;
		}
		if(sz(free)==0)
		{
			ans=(ans+x)%mod;
			ll tmp=(y*(a[i].second-a[i].first))%mod;
			ans=(ans+tmp)%mod;
		}
		else
		{
			auto it=free.begin();
			ll last=*it;
			ll extra=a[i].first-last;
			if(y*extra < x)
			{
				ll tmpp=(y*extra)%mod;
				ans=(ans+tmpp)%mod;
				free.erase(it);
			}
			else
				ans=(ans+x)%mod;
			ll tmp=(y*(a[i].second-a[i].first))%mod;
			ans=(ans+tmp)%mod;
		}
		r.insert(a[i].second);
	}
	cout<<ans<<endl;
	return 0;
}