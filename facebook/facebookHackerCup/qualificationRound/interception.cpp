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
	ll i;
	for(i=1;i<=t;i++)
	{
		ll n;
		cin>>n;
		vector<ll> degree;
		ll j;
		ll x=1;
		ll ans=0;
		for(j=0;j<=n;j++)
		{
			ll val;
			cin>>val;
			if(j==n)
			{
				if(x==0)
					ans=1;
				else
					ans=0;
				break;
			}
			if(x==0 || j+1+val==0)
				x=1;
			else
				x=0;
		}
		cout<<"Case #"<<i<<": "<<ans<<"\n";
		if(ans==1)
			cout<<"0.0\n";
	}
	return 0;
}