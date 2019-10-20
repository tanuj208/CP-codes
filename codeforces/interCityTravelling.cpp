#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=998244353;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a(1000006);
	ll i;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
	{
		cout<<a[1]<<endl;
		return 0;
	}
	ll ans=3*a[1]+a[2];
	ll x=a[1];
	for(i=3;i<=n;i++)
	{
		x=((2*x)%mod+a[i-1])%mod;
		ans=(2*ans+x+a[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}