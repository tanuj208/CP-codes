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
	ifstream inFile;
    inFile.open("topo.in");
	inFile>>t;
	while(t--)
	{
		ll n;
		inFile>>n;
		vector<ll> a,b;
		vector<ll> cycles;
		vector<ll> ncycles;
		ll i,j;
		for(i=0;i<n;i++)
		{
			ll val;
			inFile>>val;
			a.pb(val);
		}
		for(i=0;i<n;i++)
		{
			ll val;
			inFile>>val;
			b.pb(val);
			if(val!=0)
				cycles.pb(i);
			else
				ncycles.pb(i);
		}
		vector<pii> edges;
		bool poss=true;
		if(sz(cycles)==1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(i=0;i<sz(cycles)-1;i++)
			edges.pb(mp(cycles[i], cycles[i+1]));
		edges.pb(mp(cycles[sz(cycles)-1], cycles[0]));
		for(i=0;i<sz(cycles);i++)
		{
			ll tmp=b[cycles[i]]-1;
			ll tmp2=a[cycles[i]]-tmp-1;
			// cout<<cycles[i]<<" "<<tmp<<endl;
			for(j=0;j<sz(cycles);j++)
			{
				if(tmp==0)
					break;
				if(i==j || ((i==0 && j==sz(cycles)-1) || j==i-1))
					continue;
				tmp--;
				// if(cycles[i]==4)
				// 	cout<<"F"<<i<<" "<<cycles[j]<<endl;
				edges.pb(mp(cycles[j],cycles[i]));
			}
			if(tmp!=0 || tmp2<0)
			{
				cout<<-1<<endl;
				poss=false;
				break;
			}
			for(j=0;j<sz(ncycles);j++)
			{
				if(tmp2==0)
					break;
				tmp2--;
				edges.pb(mp(ncycles[j],cycles[i]));
			}
			if(tmp2!=0)
			{
				cout<<-1<<endl;
				poss=false;
				break;
			}
		}
		if(!poss)
			continue;
		vector<pii> x;
		for(i=0;i<sz(ncycles);i++)
			x.pb(mp(a[ncycles[i]], ncycles[i]));
		sort(all(x));
		vector<ll> tmp;
		for(i=0;i<sz(x);i++)
		{
			ll deg=x[i].ff;
			ll vtx=x[i].ss;
			for(j=0;j<sz(tmp);j++)
			{
				if(deg==0)
					break;
				deg--;
				edges.pb(mp(tmp[i], vtx));
			}
			if(deg!=0)
			{
				cout<<-1<<endl;
				poss=false;
				break;
			}
			tmp.pb(vtx);
		}
		if(!poss)
			continue;
		cout<<sz(edges)<<endl;
		for(i=0;i<sz(edges);i++)
			cout<<edges[i].ff+1<<" "<<1+edges[i].ss<<endl;
	}
	return 0;
}