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
	ll n;
	cin>>n;
	map<ll,ll> x;
	ll i;
	for(i=0;i<n;i++)
	{
		ll v,p;
		cin>>v>>p;
		x.insert(mp(v,p));
	}
	ll m;
	cin>>m;
	for(i=0;i<m;i++)
	{
		ll v,p;
		cin>>v>>p;
		if(x.find(v)!=x.end())
			x[v]=max(x[v],p);
		else
			x.insert(mp(v,p));
	}
	ll ans=0;
	for(auto it=x.begin();it!=x.end();it++)
		ans+=((*it).second);
	cout<<ans<<endl;
	return 0;
}