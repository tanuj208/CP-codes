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
		ll n,q;
		cin>>n>>q;
		vector<ll> a;
		map<ll,ll> x;
		ll i;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
			x[val]++;
		}
		for(i=0;i<q;i++)
		{
			ll c;
			cin>>c;
			if(c==1)
			{
				ll p,v;
				cin>>p>>v;
				ll tmp=a[p-1];
				x[tmp]--;
				if(x[tmp]==0)
					x.erase(tmp);
				x[v]++;
				a[p-1]=v;
			}
			else
			{
				ll ans=sz(x);
				if(x.find(0)!=x.end())
					ans--;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}