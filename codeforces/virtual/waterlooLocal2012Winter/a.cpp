#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"
const ll inf=1e16;
priority_queue<pair<pll,ll>,vector<pair<pll,ll > >, greater<pair<pll,ll> > > pq;
ll vis[100000];
int main()
{
    ll n,e,p;
    cin >> n >> e>>p;
    vector<pair<pll,ll> > G[100000];
	pll level[100000];
	for (ll i = 0; i < e; ++i)
	{
		ll a,b,w;
		char c;
		cin >> a >>b  >> w>>c;
		if(c=='I')
		{
			G[a].push_back(mp(mp(b,w),0));
		    G[b].push_back(mp(mp(a,w),0));
		}
		else
		{
			G[a].push_back(mp(mp(b,w),1));
	   		G[b].push_back(mp(mp(a,w),1));	
		}
	}
	lp(zz,0,p)
	{
		lp(j,0,n+1) vis[j]=0;
		ll x,y;	
		// cout<<endl;
		cin >> x >>y; //kithon laike kithe takk;
		for (ll j = 0; j < n+1; ++j)
		{
			level[j]=mp(inf,inf);
		}
		level[x]=mp(0,0);
		pq.push(mp(mp(0,0),x));
		while( !pq.empty() )
		{
			ll a,b;
			a=pq.top().F.F;
			b=pq.top().F.S;
			ll prev=pq.top().S;
			pq.pop();
			// cout<<a<<" "<<b<<" "<<c<<endl;
			// cout<<G[prev].size()<<endl;
			if(vis[prev]==0)
			{
				vis[prev]=1;
				for (ll j = 0; j < G[prev].size(); ++j)
				{
					ll val=G[prev][j].F.S;
					ll z=G[prev][j].F.F;
					if(!vis[z])
					{
						if(G[prev][j].S==0)
						{
							if(level[z].F>=level[prev].F)
							{
								if(level[z].F>level[prev].F)
								{
									level[z].F=level[prev].F;
									level[z].S=level[prev].S+val;
									pq.push(mp(level[z],z));
								}
								else
								{
									if(level[z].S>level[prev].S+val);	
									{
										level[z].S=level[prev].S+val;	
										pq.push(mp(level[z],z));
									}
								}
							}

						}
						else
						{
							if(level[z].F>=level[prev].F+val)
							{
								if(level[z].F>level[prev].F+val)
								{
									level[z].F=level[prev].F+val;
									level[z].S=level[prev].S+val;	
									pq.push(mp(level[z],z));

								}
								else
								{
									if(level[z].S>level[prev].S+val);	
									{
										level[z].S=level[prev].S+val;
										pq.push(mp(level[z],z));
									}
								}
							}
						}
					}
				}
			}
			// pq.pop();
		}
		if(x>=n || y>=n)
			cout<<"IMPOSSIBLE"<<endl;
		else if(level[y].F>=inf&&level[y].S>=inf)
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<level[y].F<<" "<<level[y].S<<endl;
		}
	}
}