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
	vector<pii> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(mp(val,i));
	}
	vector<ll> ans(100,-1);
	sort(a.begin(),a.end());
	for(i=0;i<n-1;i++)
	{
		if(a[i].first!=a[i+1].first)
		{
			ans[a[i].second]=a[i].first;
		}
	}
	ans[a[n-1].second]=a[n-1].first;
	ll size=0;
	for(i=0;i<n;i++)
	{
		if(ans[i]!=-1)
			size++;
	}
	cout<<size<<endl;
	for(i=0;i<n;i++)
	{
		if(ans[i]!=-1)
			cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}