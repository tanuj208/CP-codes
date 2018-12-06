#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> ad[10005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		if(sz(ad[i])==1)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}