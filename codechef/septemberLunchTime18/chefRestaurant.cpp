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
		ll n,m;
		cin>>n>>m;
		ll i;
		vector<ll> l,r;
		for(i=0;i<n;i++)
		{
			ll a,b;
			cin>>a>>b;
			l.pb(a);
			r.pb(b);
		}
		sort(l.begin(),l.end());
		sort(r.begin(),r.end());
		for(i=0;i<m;i++)
		{
			ll t;
			cin>>t;
			ll ind=upper_bound(l.begin(),l.end(), t)-l.begin();
			ind--;
			if(ind==-1)
			{
				cout<<l[0]-t<<"\n";
				continue;
			}
			if(r[ind]<=t)
			{
				if(ind+1<n)
					cout<<l[ind+1]-t<<"\n";
				else
					cout<<"-1\n";
				continue;
			}
			cout<<"0\n";
		}
	}
	return 0;
}