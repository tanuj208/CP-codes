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
	ll n,c;
	cin>>n>>c;
	ll i;
	vector<ll> a;
	ll cval=0;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		if(val==c)
			cval++;
	}
	ll ans=0;
	set<pii, greater<pii> > x;
	map<ll,ll> cntrr;
	ll j=0;
	ll tmpMax=0;
	ll cvals=0;
	i=0;
	for(j=0;j<n;j++)
	{
		cntrr[a[j]]++;
		if(cntrr[a[j]]==1)
			x.insert(mp(1,a[j]));
		else
		{
			x.erase(mp(cntrr[a[j]]-1,a[j]));
			x.insert(mp(cntrr[a[j]], a[j]));
		}
		tmpMax=x.begin()->first;
		if(a[j]==c)
			cvals++;
		ans=max(ans,tmpMax-cvals);
		while(tmpMax-cvals<=0 && i<=j)
		{
			if(a[i]==c)
				cvals--;
			x.erase(mp(cntrr[a[i]], a[i]));
			cntrr[a[i]]--;
			x.insert(mp(cntrr[a[i]], a[i]));
			tmpMax=x.begin()->first;
			i++;
		}
		ans=max(ans, tmpMax-cvals);
	}
	while(i<n)
	{
		if(a[i]==c)
			cvals--;
		x.erase(mp(cntrr[a[i]], a[i]));
		cntrr[a[i]]--;
		x.insert(mp(cntrr[a[i]], a[i]));
		tmpMax=x.begin()->first;
		ans=max(ans, tmpMax-cvals);
		i++;
	}
	cout<<cval+ans<<endl;
	return 0;
}