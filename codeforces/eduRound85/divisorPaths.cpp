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

ll mod=998244353;

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
	ll d;
	cin>>d;
	vector<ll> p;
	ll i;
	ll tmp = d;
	for(i=2;i<=sqrt(d);i++)
	{
		ll cnt=0;
		while(tmp%i==0)
		{
			tmp/=i;
			cnt++;
		}
		if(cnt!=0)
			p.pb(i);
	}
	if(tmp != 1)
		p.pb(tmp);
	vector<ll> fac;
	fac.pb(1);
	for(i=1;i<=100000;i++)
	{
		ll tmp = fac[i-1] * i;
		tmp%=mod;
		fac.pb(tmp);
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll u,v;
		cin>>u>>v;
		ll t1 = min(u,v);
		ll t2 = max(u,v);
		ll s1=0;
		ll den1=1;
		ll den2=1;
		ll s2=0;

		for(i=0;i<sz(p);i++)
		{
			ll cnt1=0,cnt2=0;
			while(t1%p[i] == 0)
			{
				t1 /= p[i];
				cnt1++;
			}
			while(t2%p[i] == 0)
			{
				t2 /= p[i];
				cnt2++;
			}
			if(cnt1 > cnt2)
			{
				s2 += cnt1-cnt2;
				den2 = (den2 * fac[cnt1-cnt2]) % mod;
			}
			else if(cnt2 > cnt1)
			{
				s1 += cnt2-cnt1;
				den1 = (den1 * fac[cnt2-cnt1]) % mod;
			}
		}
		ll num1 = fac[s1];
		ll ans1 = (num1 * power(den1, mod-2)) % mod;

		ll ans2 = (fac[s2] * power(den2, mod-2)) % mod;
		cout<<((ans1 * ans2)%mod)<<endl;
	}
	return 0;
}