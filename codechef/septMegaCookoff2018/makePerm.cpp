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
		vector<ll> a;
		vector<ll> cnt(100005,0);
		ll ans=0;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			if(val<=n)
				cnt[val]++;
			else
				ans++;
			a.pb(val);
		}
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>1)
				ans+=cnt[i]-1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}