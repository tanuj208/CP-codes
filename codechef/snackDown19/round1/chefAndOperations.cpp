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
		vector<ll> a,b;
		ll i;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			b.pb(val);
		}
		ll e=0;
		for(i=0;i<n-2;i++)
		{
			if(a[i]>b[i])
			{
				cout<<"NIE\n";
				e=1;
				break;
			}
			ll cnt=b[i]-a[i];
			a[i]+=cnt;
			a[i+1]+=2*cnt;
			a[i+2]+=3*cnt;
		}
		if(e==0)
		{
			for(i=0;i<n;i++)
			{
				if(a[i]!=b[i])
				{
					cout<<"NIE\n";
					e=1;
					break;
				}
			}
		}
		if(e==1)
			continue;
		cout<<"TAK\n";
	}
	return 0;
}