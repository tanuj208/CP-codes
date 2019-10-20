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

vector<ll> ad[1000005];
vector<ll> indeg(1000005,0);
vector<ll> outdeg(1000005,0);
vector<pii> ans;
vector<bool> removed(1000005);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	for(i=0;i<=1000000;i++)
		removed[i]=false;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[v].pb(u);
		indeg[v]++;
		outdeg[u]++;
	}
	set<pii, greater<pii> > a1;  // all with outdegree zero, sorted by indegree
	set<pii, greater<pii> > a2; // sorted by indegree outdegree != zero

	for(i=1;i<=n;i++)
	{
		if(outdeg[i]==0)
			a1.insert(mp(indeg[i], i));
		else
			a2.insert(mp(indeg[i], i));
	}
	while(!a1.empty() || !a2.empty())
	{
		if(sz(a1)>=2)
		{
			auto it1=a1.begin();
			ll u=it1->second;
			a1.erase(it1);
			it1=a1.begin();
			ll v=it1->second;
			a1.erase(it1);
			ans.pb(mp(u,v));
			removed[u]=true;
			removed[v]=true;

			for(i=0;i<sz(ad[u]);i++)
			{
				ll x=ad[u][i];
				if(x==u || x==v || removed[x])
					continue;
				outdeg[x]--;
				if(outdeg[x]==0)
				{
					a2.erase(mp(indeg[x], x));
					a1.insert(mp(indeg[x], x));
				}
			}
			for(i=0;i<sz(ad[v]);i++)
			{
				ll x=ad[v][i];
				if(x==u || x==v || removed[x])
					continue;
				outdeg[x]--;
				if(outdeg[x]==0)
				{
					a2.erase(mp(indeg[x], x));
					a1.insert(mp(indeg[x], x));
				}
			}
		}
		else if(sz(a1)==1)
		{
			auto it=a1.begin();
			ll v=it->second;
			removed[v]=true;
			a1.erase(it);
			for(i=0;i<sz(ad[v]);i++)
			{
				ll x=ad[v][i];
				if(removed[x])
					continue;
				outdeg[x]--;
				if(outdeg[x]==0)
				{
					a2.erase(mp(indeg[x], x));
					a1.insert(mp(indeg[x], x));
				}
			}
			ans.pb(mp(v,-1));
		}
	}
	cout<<sz(ans)<<endl;
	for(i=0;i<sz(ans);i++)
	{
		if(ans[i].second==-1)
			cout<<"1 "<<ans[i].first<<"\n";
		else
			cout<<"2 "<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}