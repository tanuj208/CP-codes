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

ll n,k;
map<ll, map<ll,ll> > ad;
// multiset<ll> ad[100005];
map<pii, ll> xx;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	ll i;
	for(i=0;i<k;i++)
	{
		ll x,y;
		cin>>x>>y;
		ad[x][y]++;
		ad[y][x]++;
		xx[mp(min(x, y), max(x, y))]++;
	}
	vector<ll> eaten(n+5,0);
	queue<ll> q;
	ll ans=0;
	while(!xx.empty())
	{
		auto tmp=xx.begin();
		xx.erase(xx.begin());
		ll fx = tmp->first.ff;
		ll fy=tmp->first.ss;
		ans+=tmp->second-1;
		ad[fx].erase(fy);
		ad[fy].erase(fx);
		eaten[fx]=1;
		eaten[fy]=1;
		queue<ll> q;
		q.push(fx);
		q.push(fy);
		while(!q.empty())
		{
			ll snk = q.front();
			q.pop();
			for(auto it=ad[snk].begin();it!=ad[snk].end();it++)
			{
				ll snk2=it->first;
				if(eaten[snk2]==1)
					ans+=it->second;
				else
				{
					ans+=it->second-1;
					eaten[snk2]=1;
					q.push(snk2);
				}
				pii cur_pair = mp(min(snk, snk2), max(snk, snk2));
				xx.erase(cur_pair);
				ad[snk2].erase(snk);
			}
			ad[snk].clear();
		}
	}
	cout<<ans<<endl;
	return 0;
}