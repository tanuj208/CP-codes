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
	ll ans=0;
	ans+=(n/100);
	n-=100*(n/100);
	ans+=(n/20);
	n-=20*(n/20);
	ans+=(n/10);
	n-=10*(n/10);
	ans+=(n/5);
	n-=5*(n/5);
	ans+=n;
	cout<<ans<<endl;
	return 0;
}