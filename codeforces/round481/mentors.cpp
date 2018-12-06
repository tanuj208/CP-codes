#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<pii> r;
	ll i,val;
	ll sss[200004];
	for(i=0;i<n;i++)
	{
		cin>>val;
		sss[i]=val;
		r.pb(mp(val,i));
	}
	vector<ll> ad[200005];
	for(i=0;i<k;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	sort(r.begin(),r.end());
	ll ans[200005];
	ans[r[0].second]=0;
	ll anss=0;
	for(i=1;i<n;i++)
	{
		ll skill=r[i].first;
		if(skill>r[i-1].first)
			anss=i;
		ll j;
		ll x=r[i].second;
		ans[x]=anss;
		for(j=0;j<sz(ad[x]);j++)
		{
			ll v=ad[x][j];
			if(sss[v]<skill)
				ans[x]--;
		}
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}