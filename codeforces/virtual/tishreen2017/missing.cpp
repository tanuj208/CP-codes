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
		ll i;
		ll prev=0;
		ll ans=-1;
		for(i=1;i<n;i++)
		{
			ll val;
			cin>>val;
			if(val!=prev+1)
				ans=prev+1;
			prev=val;
		}
		if(ans==-1)
			ans=n;
		cout<<ans<<"\n";
	}
	return 0;
}