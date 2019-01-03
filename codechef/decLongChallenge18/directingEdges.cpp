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

vector<pii> ad[200005];
vector<ll> deg(200005);
vector<ll> ans(200005);
vector<ll> inDeg(200005);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll i;
		for(i=0;i<=200000;i++)
		{
			deg[i]=0;
			ad[i].clear();
			ans[i]=-1;
			inDeg[i]=0;
		}
		for(i=0;i<m;i++)
		{
			ll u,v;
			cin>>u>>v;
			ad[u].pb(mp(v,i+1));
			ad[v].pb(mp(u,-i-1));
			deg[u]++;
			deg[v]++;
		}
		if(m%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		set<pii> x;
		for(i=1;i<=n;i++)
			x.insert(mp(deg[i],i));
		while(!x.empty())
		{
			auto it=x.begin();
			ll degree=it->first;
			ll v=it->second;
			ll i;
			x.erase(it);
			if(degree==1)
			{
				bool lena;
				if(inDeg[v]%2==1)
					lena=true;
				else
					lena=false;
				for(i=0;i<sz(ad[v]);i++)
				{
					ll xx=ad[v][i].first;
					ll eno=ad[v][i].second;
					bool tmp;
					if(eno<0)
						tmp=false,eno=-eno;
					else
						tmp=true;
					if(ans[eno]!=-1)
						continue;
					if(lena)
					{
						if(tmp)
							ans[eno]=1;
						else
							ans[eno]=0;
						inDeg[v]++;
					}
					else
					{
						if(tmp)
							ans[eno]=0;
						else
							ans[eno]=1;
						inDeg[xx]++;
					}
					x.erase(mp(deg[xx], xx));
					deg[xx]--;
					if(deg[xx]>0)
						x.insert(mp(deg[xx], xx));
					break;
				}
			}
			else
			{
				deg[v]--;
				x.insert(mp(deg[v], v));
				for(i=0;i<sz(ad[v]);i++)
				{
					ll xx=ad[v][i].first;
					ll eno=ad[v][i].second;
					bool tmp;
					if(eno<0)
						tmp=false,eno=-eno;
					else
						tmp=true;
					if(ans[eno]!=-1)
						continue;
					ans[eno]=0;
					if(tmp)
						inDeg[xx]++;
					else
						inDeg[v]++;
					x.erase(mp(deg[xx], xx));
					deg[xx]--;
					if(deg[xx]>0)
						x.insert(mp(deg[xx], xx));
					break;
				}
			}
		}

		for(i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}