#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> a;

pii ans(ll r)
{
	ll aa=lower_bound(a.begin(),a.end(),r)-a.begin();
	if(aa==0)
		return mp(1,r);
	else
		return mp(aa+1,r-a[aa-1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i;
	cin>>i;
	a.pb(i);
	for(i=1;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(a[i-1]+val);
	}
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		pii x=ans(val);
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}