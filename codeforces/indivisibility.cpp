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
	cout<<n-((n/2+n/3+n/5+n/7+n/30+n/42+n/70+n/105)-(n/6+n/10+n/14+n/15+n/21+n/35+n/210))<<endl;
	return 0;
}