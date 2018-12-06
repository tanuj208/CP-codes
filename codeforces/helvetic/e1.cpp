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
	ll r,b;
	cin>>r>>b;
	vector<pii> rebel;
	vector<pii> spaceship;
	ll i;
	for(i=0;i<r;i++)
	{
		ll x,y;
		cin>>x>>y;
		rebel.pb(mp(x,y));
	}
	for(i=0;i<b;i++)
	{
		ll x,y;
		cin>>x>>y;
		spaceship.pb(mp(x,y));
	}
	if(r==b)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}