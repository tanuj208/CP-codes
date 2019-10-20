#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> c(100004,-1);
vector<ll> d(100004,-1);
ll n;

ll right(ll x)
{
	if(x==n-1)
		return n-1;
	if(c[x+1]==-1)
		return x;
	c[x]=right(c[x+1]);
	return c[x];
}

ll left(ll x)
{
	if(x==0)
		return 0;
	if(d[x-1]==-1)
		return x;
	d[x]=left(d[x-1]);
	return d[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pii> a;
	cin>>n;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(mp(val,i));
	}
	sort(a.begin(),a.end());
	ll ans=a[0].first+1;
	ll maxl=0;
	ll loc=0;
	ll total=0;
	ll maxrange=0;
	for(i=0;i<n;i++)
	{
		ll ind=a[i].second;
		c[ind]=ind;
		d[ind]=ind;
		ll r=right(ind);
		ll l=left(ind);
		if(l==r)
			loc++;
		maxrange=max(maxrange,r-l+1);
		total=max(total,loc*maxrange);
		if(i+1==total)
		{
			if(maxl<loc)
				maxl=loc,ans=a[i].first+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}