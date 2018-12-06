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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,val;
		ll ans=0;
		for(i=0;i<n;i++)
		{
			cin>>val;
			ans=ans^(2*val);
		}
		cout<<ans<<endl;
	}
	return 0;
}