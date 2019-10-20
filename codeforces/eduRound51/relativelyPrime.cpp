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
	ll l,r;
	cin>>l>>r;
	cout<<"YES\n";
	ll i;
	for(i=l;i<=r;i+=2)
		cout<<i<<" "<<i+1<<"\n";
	return 0;
}