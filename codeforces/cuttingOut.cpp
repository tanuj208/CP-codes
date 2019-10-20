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
vector<pii> x;
ll n,k;

bool possible(ll c)
{
	if(c==1)
		return true;
	ll i;
	ll cntr=0;
	for(i=0;i<sz(x);i++)
		cntr+=x[i].first/c;
	if(cntr>=k)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	vector<ll> cnt(200005,0);
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		cnt[val]++;
	}
	for(i=1;i<=200000;i++)
		if(cnt[i]!=0)
			x.pb(mp(cnt[i], i));
	sort(x.begin(),x.end());
	reverse(x.begin(),x.end());
	ll l=0;
	ll r=200005;
	ll mid=(l+r)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if(possible(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	while(!possible(mid) && mid>=1)
		mid--;
	while(possible(mid+1) && mid+1<=n)
		mid++;
	ll cntr=0;
	for(i=0;i<sz(x);i++)
	{
		ll add=x[i].first/mid;
		if(cntr+add>k)
			add=k-cntr;
		cntr+=add;
		for(ll j=0;j<add;j++)
			cout<<x[i].second<<" ";
		if(cntr==k)
			break;
	}
	cout<<endl;
	return 0;
}