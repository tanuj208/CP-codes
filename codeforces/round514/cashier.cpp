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
	ll n,l,a;
	cin>>n>>l>>a;
	vector<pii> x;
	ll i;
	for(i=0;i<n;i++)
	{
		ll q,w;
		cin>>q>>w;
		x.pb(mp(q,w));
	}
	ll ans=0;
	ll ll=0;
	for(i=0;i<n;i++)
	{
		ans+=(x[i].first-ll)/a;
		ll=x[i].first+x[i].second;
	}
	ans+=(l-ll)/a;
	cout<<ans<<endl;
	return 0;
}