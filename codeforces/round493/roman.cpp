#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll func(ll x)
{
	return 4+6*(x-1)+2*(x-1)*(x-2)+((x-1)*(x-2)*(x-3))/6;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	cout<<func(n)<<endl;
	return 0;
}