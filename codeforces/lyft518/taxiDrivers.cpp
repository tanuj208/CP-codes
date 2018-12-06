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
	ll n,m;
	cin>>n>>m;
	vector<ll> x,t;
	ll i;
	for(i=0;i<n+m;i++)
	{
		ll val;
		cin>>val;
		x.pb(val);
	}
	for(i=0;i<n+m;i++)
	{
		ll val;
		cin>>val;
		t.pb(val);
	}
	vector<pii> ans;
	ll nearest=-1;
	ll dist=0;
	for(i=0;i<n+m;i++)
	{
		if(t[i]==1)
		{
			nearest=i;
			dist=x[i];
		}
		else
			ans.pb(mp(nearest, x[i]-dist));
	}
	nearest=-1;
	dist=0;
	ll cntr=n-1;
	for(i=n+m-1;i>=0;i--)
	{
		if(t[i]==1)
		{
			nearest=i;
			dist=x[i];
		}
		else
		{
			if(nearest==-1)
			{
				cntr--;
				continue;
			}
			if(ans[cntr].first==-1 || ans[cntr].second>dist-x[i])
			{
				ans[cntr].first=nearest;
				ans[cntr].second=dist-x[i];
			}
			cntr--;
		}
	}
	vector<ll> cor(200005,-1);
	cntr=0;
	for(i=0;i<n+m;i++)
	{
		if(t[i]==1)
		{
			cor[i]=cntr;
			cntr++;
		}
	}
	vector<ll> anss(100005,0);
	for(i=0;i<n;i++)
		anss[cor[ans[i].first]]++;
	for(i=0;i<m;i++)
		cout<<anss[i]<<" ";
	cout<<endl;
	return 0;
}