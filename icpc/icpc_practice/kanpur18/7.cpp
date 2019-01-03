#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define tp pair<pair<ll,ll>,ll>
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define endl "\n"


typedef long long ll;

const ll N=1e5+3,inf=1e12;
set<pll> G[N];
ll vis[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin >> n >> m;
	lp(i,0,m)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		G[a].insert(mp(c,b));
		G[b].insert(mp(c,a));
	}	
	ll s,t;
	cin >> s >> t;
	priority_queue <tp,vector<tp>,greater<tp> > pq;
	set<pll> C;
	ll dis[N];
	lp(i,0,n+1)dis[i]=inf;
	dis[0]=0;
	pq.push(mp(mp(0,s),-1));
	while(!pq.empty())
	{
		ll a=pq.top().ff.ss;
		ll b=pq.top().ff.ff;
		ll c=pq.top().ss;
		// cout<<a<<" "<<b<<" "<<c<<endl;
		pq.pop();
		vpll V;
		if(vis[a]==0)
		{
			vis[a]=1;
			C.insert(mp(a,c));
			dis[a]=b;
			set<pll>:: iterator it;
			for(it=G[a].begin();it!=G[a].end();it++)
			{
				ll x=(*it).ss;
				ll ec=(*it).ff;
				if(a==s)c=ec;
				if(C.find(mp(x,ec))==C.end())
				{
					pq.push(mp(mp((ec==c ? 0 : 1) + b,x),ec));
				}
			}
			it=G[a].lower_bound(mp(c,-inf));
			while(it!=G[a].end()&&(*it).ff==c)
			{
				V.pb(*it);
				it++;
			}
		}
		else if((b==dis[a]&&C.find(mp(a,c))==C.end()))
		{
			C.insert(mp(a,c));
			dis[a]=b;
			set<pll>:: iterator it;
			it=G[a].lower_bound(mp(c,-inf));
			while(it!=G[a].end()&&(*it).ff==c)
			{
				V.pb(*it);
				ll x=(*it).ss;
				ll ec=(*it).ff;
				if(a==s)c=ec;

				if(C.find(mp(x,ec))==C.end())
				{
					pq.push(mp(mp((ec==c ? 0 : 1) + b,x),ec));
				}
				it++;
			}
		}
		lp(i,0,V.size())
		{
			G[a].erase(V[i]);
		}
		V.clear();
	}
	cout<<dis[t]<<endl;
}
