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
	ll n,i;
	cin>>n;
	ll onD=1;
	ll onABC=0;
	for(i=1;i<=n;i++)
	{
		ll tmp1=(onD*3+onABC*2)%mod;
		onD=onABC%mod;
		onABC=tmp1;
	}
	cout<<onD<<endl;
	return 0;
}