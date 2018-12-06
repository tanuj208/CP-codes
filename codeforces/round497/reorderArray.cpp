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
	sort(a.begin(),a.end());
	ll last=0;
	ll ans=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[last])
		{
			ans++;
			last++;
		}
	}
	cout<<ans<<endl;
	return 0;
}