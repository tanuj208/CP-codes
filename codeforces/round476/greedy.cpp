#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll temp=1e18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,m,D;
	cin>>n>>k>>m>>D;
	ll d;
	ll ans=0;
	for(d=1;d<=D;d++)
	{
		ll x;
		if(d>(temp/k))
			break;
		x=ceil(double(n)/double(1+k*d-k));
		if((n/(x*k))-((d*k+1-k)/k)>0)
			continue;
		// cout<<x<<endl;
		if(x>m)
			x=m;
		ans=max(ans,x*d);
	}
	cout<<ans<<endl;
	return 0;
}