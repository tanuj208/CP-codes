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

// set<pair<pii,ll> > x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	vector<ll> av,cst;
	vector<pii> tmp;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		av.pb(val);
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		cst.pb(val);
		tmp.pb(mp(val,i));
	}
	sort(all(tmp));
	ll j=0;
	// for(i=0;i<n;i++)
	while(m--)
	{
		ll t,d;
		cin>>t>>d;
		ll ans=0;
		t--;
		if(av[t]>=d)
		{
			av[t]-=d;
			ans+=d*cst[t];
			cout<<ans<<endl;
		}
		else
		{
			d-=av[t];
			ans+=av[t]*cst[t];
			av[t]=0;
			while(d!=0 && j<n)
			{
				ll index=tmp[j].ss;
				if(av[index]>=d)
				{
					av[index]-=d;
					ans+=d*cst[index];
					d=0;
				}
				else
				{
					d-=av[index];
					ans+=av[index]*cst[index];
					av[index]=0;
					j++;
				}
			}
			if(d==0)
				cout<<ans<<endl;
			else
				cout<<0<<endl;
		}
	}
	return 0;
}