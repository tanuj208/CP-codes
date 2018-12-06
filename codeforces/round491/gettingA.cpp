#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> g;
ll n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,val;
	cin>>n;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		g.pb(val);
		sum+=val;
	}
	sort(g.begin(),g.end());
	ll ans=0;
	double x=4.5*(double)n;
	i=0;
	while(sum<x)
	{
		sum+=(5-g[i]);
		i++;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}