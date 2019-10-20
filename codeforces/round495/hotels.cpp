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
	ll n,d;
	cin>>n>>d;
	ll i,val;
	vector<ll> a;
	ll ans=2;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=1;i<n;i++)
	{
		ll x=a[i-1]+d;
		if(a[i-1]+d<a[i]-d)
			ans+=2;
		else if(a[i-1]+d==a[i]-d)
			ans++;

	}
	cout<<ans<<endl;
	return 0;
}