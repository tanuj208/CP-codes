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

map<ll, vector<pii>> x; // velocity versus vector of segments

bool overlap(ll l1, ll r1, ll l2, ll r2)
{
	if(l2<=r1)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	vector<pii> emp;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,j;
		x.clear();
		for(i=0;i<n;i++)
		{
			ll l,r,v;
			cin>>l>>r>>v;
			if(x.find(v)==x.end())
				x[v] = emp;
			x[v].pb(mp(l, r));
		}
		bool ans=true;
		for(auto it=x.begin();it!=x.end();it++)
		{
			vector<pii> segs=it->second;
			vector<ll> vels(sz(segs), 0);
			sort(all(segs));
			vels[0]=1;
			for(i=1;i<sz(segs);i++)
			{
				if(overlap(segs[i-1].ff, segs[i-1].ss, segs[i].ff, segs[i].ss))
				{
					if(vels[i-1]==1)
						vels[i]=2;
					else
						vels[i]=1;
				}
				else
					vels[i]=vels[i-1];
			}
			for(i=0;i<sz(segs);i++)
				for(j=i+1;j<sz(segs);j++)
					if(overlap(segs[i].ff, segs[i].ss, segs[j].ff, segs[j].ss))
						if(vels[i]==vels[j])
							ans=false;
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}