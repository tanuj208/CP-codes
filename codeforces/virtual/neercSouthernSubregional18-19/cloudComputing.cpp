#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<pair<pii, ll> ,null_type,less<pair<pii, ll> >,rb_tree_tag,tree_order_statistics_node_update> pbds;

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

pbds x; // price and number of cores and index
set<pii> rs;  // r and index
vector<pair<pii,pii> > t; // l, r, cores, price
ll ind;
ll curp,curc;
ll n,k,m;

void insert(ll j)
{
	pair<pii, ll> tmp=mp(mp(t[j].second.second, t[j].second.first), j);
	
	x.insert(tmp);
	ll index = x.order_of_key(tmp);
	if(index<ind)
	{
		curp+=t[j].second.second;
		curc+=t[j].second.first;
		ind++;
		auto it=x.find_by_order(ind);
		while(true)
		{
			ll cores=it->first.first;
			ll price=it->first.second;
			if(curc-cores>=k)
			{
				curc-=cores;
				curp-=price;
				it--;
				ind--;
			}
			else
				break;
		}
	}

	rs.insert(mp(t[j].first.second, j));
}

void remove(ll j)
{
	pair<pii, ll> tmp=mp(mp(t[j].second.second, t[j].second.first), j);

	ll index = x.order_of_key(tmp);
	if(index<ind)
	{
		curp-=t[j].second.second;
		curc-=t[j].second.first;
		auto it=x.find_by_order(ind);
		ind--;
		while(true && it!=x.end())
		{
			if(curc>=k)
				break;
			ind++;
			ll cores=it->first.first;
			ll price=it->first.second;
			curc+=cores;
			curp+=price;
			it++;
		}
	}

	x.erase(tmp);
	rs.erase(mp(t[j].first.second, j));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>m;
	ll i;
	for(i=0;i<m;i++)
	{
		ll l,r,c,p;
		cin>>l>>r>>c>>p;
		t.pb(mp(mp(l,r),mp(c,p)));
	}
	sort(t.begin(),t.end());

	ll j=0;
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		while(true)
		{
			if(sz(rs)==0)
				break;
			auto it=rs.begin();
			if(it->first>=i)
				break;
			remove(it->second);
		}
		while(t[j].first.first<=i)
		{
			insert(j);
			j++;
		}
		ans+=curp;
	}
	cout<<ans<<endl;
	return 0;
}