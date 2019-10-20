#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

pii cnt[2005][2005];

ll dist(ll i,ll j,ll x,ll y)
{
	return (i-x)*(i-x)+(j-y)*(j-y);
}

ll n,m;

void func(ll x,ll y,ll r,ll s)
{
	ll i,j;
	for(i=0;i<=2000;i++)
	{
		for(j=0;j<=2000;j++)
		{
			ll ii=i-1000;
			ll jj=j-1000;
			if(dist(ii,jj,x,y)<=r*r && cnt[i][j].second<m)
				cnt[i][j].first+=s,cnt[i][j].second++;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,j;
		for(i=0;i<=2000;i++)
			for(j=0;j<=2000;j++)
				cnt[i][j]=mp(0,0);
		cin>>n>>m;
		vector<pair<pii,pii> > xx;
		for(i=0;i<n;i++)
		{
			ll x,y,r,s;
			cin>>x>>y>>r>>s;
			xx.pb(mp(mp(s,r),mp(x,y)));
		}
		sort(xx.begin(),xx.end());
		reverse(xx.begin(),xx.end());
		for(i=0;i<n;i++)
		{
			ll x=xx[i].second.first;
			ll y=xx[i].second.second;
			ll r=xx[i].first.second;
			ll s=xx[i].first.first;
			func(x,y,r,s);
		}
		ll ans=0;
		for(i=0;i<=2000;i++)
			for(j=0;j<=2000;j++)
				ans=max(ans,cnt[i][j].first);
		cout<<ans<<"\n";
	}
	return 0;
}