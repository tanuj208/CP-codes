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
		vector<ll> a;
		ll i;
		ll val;
		cin>>val;
		a.pb(val);
		for(i=0;i<n-1;i++)
		{
			cin>>val;
			a.pb(val+a[i]);
		}
		ll know=1;
		ll days=0;
		while(know<n)
		{
			know+=a[know-1];
			days++;
		}
		cout<<days<<"\n";
	}
	return 0;
}