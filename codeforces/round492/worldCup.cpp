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
	ll n;
	cin>>n;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	ll x=LLONG_MAX;
	ll ans=-1;
	for(i=0;i<n;i++)
	{
		ll xx=a[i]-i;
		xx=(xx+n-1)/n;
		if(x>xx)
		{
			x=xx;
			ans=i+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}