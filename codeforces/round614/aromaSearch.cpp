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
	ll x0,y0,ax,ay,bx,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	vector<pii> cor;
	cor.pb(mp(x0,y0));
	ll i;
	for(i=0;i<100;i++)
	{
		ll x=cor[i].ff;
		ll y=cor[i].ss;
		if(ax>(1e18/x))
			break;
		ll newx=ax*x+bx;
		if(ay>(1e18/y))
			break;
		ll newy=ay*y+by;
		cor.pb(mp(newx,newy));
	}
	ll ans=0;
	ll curtime=0;
	for(i=0;i<sz(cor);i++)
	{
		ll curans=0;
		curtime=abs(xs-cor[i].ff)+abs(ys-cor[i].ss);
		if(curtime>t)
			continue;
		curans=1;
		ll j;
		//direction down
		for(j=i-1;j>=0;j--)
		{
			curtime+=abs(cor[j+1].ff-cor[j].ff)+abs(cor[j+1].ss-cor[j].ss);
			if(curtime>t)
				break;
			curans++;
		}
		if(curtime<t && i<sz(cor)-1)
		{
			curtime+=abs(cor[0].ff-cor[i+1].ff)+abs(cor[0].ss-cor[i+1].ss);
			if(curtime<=t)
			{
				curans++;
				for(j=i+2;j<sz(cor);j++)
				{
					curtime+=abs(cor[j].ff-cor[j-1].ff) + abs(cor[j].ss-cor[j-1].ss);
					if(curtime>t)
						break;
					curans++;
				}
			}
		}
		ans=max(ans, curans);
		curans=1;


		//direction up
		for(j=i+1;j<sz(cor);j++)
		{
			curtime+=abs(cor[j].ff-cor[j-1].ff) + abs(cor[j].ss-cor[j-1].ss);
			if(curtime>t)
				break;
			curans++;
		}
		if(curtime<t && i>0)
		{
			curtime+=abs(cor[i-1].ff-cor[sz(cor)-1].ff)+abs(cor[i-1].ss-cor[sz(cor)-1].ss);
			if(curtime<=t)
			{
				curans++;
				for(j=i-2;j>=0;j--)
				{
					curtime+=abs(cor[j+1].ff-cor[j].ff)+abs(cor[j+1].ss-cor[j].ss);
					if(curtime>t)
						break;
					curans++;
				}
			}
		}
		ans=max(ans, curans);
	}
	cout<<ans<<endl;


	return 0;
}