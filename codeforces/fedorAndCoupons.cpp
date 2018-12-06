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

bool isValid(ll len, bool flag)
{
	vector<pair<pii,ll> > tmp;
	ll i,j;
	for(i=0;i<n;i++)
		if(x[i].second-len+1>=x[i].first)
			tmp.pb(mp(mp(x[i].first, x[i].second-len+1), i));

	sort(tmp.begin(),tmp.end());

	i=0;
	ll curSize=0;
	set<pair<pii, ll> > xx;
	for(j=0;j<sz(tmp);j++)
	{
		while(sz(xx)>0 && xx.begin()->first.first < tmp[j].first.first)
			xx.erase(xx.begin());
		xx.insert(mp(mp(tmp[j].first.second, tmp[j].first.first), tmp[j].second));
		if(sz(xx)>=k)
		{
			if(flag)
			{
				for(auto it=xx.begin();it!=xx.end();it++)
					cout<<1+it->second<<" ";
				cout<<endl;
			}
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	ll i;
	for(i=0;i<n;i++)
	{
		ll l,r;
		cin>>l>>r;
		x.pb(mp(l,r));
	}
	ll l=0;
	ll r=10000000000;
	ll mid=(l+r)/2;
	ll p=-1;
	while(l<r)
	{
		mid=(l+r)/2;
		if(p==mid)
			mid++;
		p=mid;
		if(isValid(mid, false))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
	bool tmpp=isValid(l, true);
	if(l==0)
	{
		for(i=1;i<=k;i++)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}