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
	ll i,val;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	set<ll> x;
	ll cnt[100005];
	for(i=n-1;i>=0;i--)
	{
		x.insert(a[i]);
		cnt[i]=sz(x);
	}
	x.clear();
	ll ans=0;
	for(i=0;i<n-1;i++)
	{
		if(x.find(a[i])!=x.end())
			continue;
		x.insert(a[i]);
		ans+=cnt[i+1];
	}
	cout<<ans<<endl;
	return 0;
}