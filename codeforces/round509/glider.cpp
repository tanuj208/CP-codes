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
	ll n,h;
	cin>>n>>h;
	vector<pii> a;
	vector<ll> cmp;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	cmp.pb(0);
	for(i=1;i<n;i++)
		cmp.pb(cmp[i-1]+a[i].first-a[i-1].second);
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ll x=0;
		ll st=a[i].first;
		ll h1=h+cmp[i];
		ll ind=lower_bound(cmp.begin(),cmp.end(),h1)-cmp.begin();
		ind--;
		x=a[ind].second-a[i].first;
		h1-=cmp[ind];
		x+=h1;
		ans=max(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}