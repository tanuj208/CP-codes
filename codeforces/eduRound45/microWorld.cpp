#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> swall(200005,-1);

ll nextEmpty(ll x)
{
	if(swall[x]==-1 || swall[x]==x)
		return x;
	swall[x]=nextEmpty(swall[x]);
	return swall[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	for(i=1;i<n;i++)
	{
		ll x=a[i]-k;
		ll j=lower_bound(a.begin(),a.end(),x)-a.begin();
		ll jj=nextEmpty(j);
		if(a[jj]!=a[i])
			swall[jj]=i;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(swall[i]==-1 || swall[i]==i)
			ans++;
		else
			i=swall[i]-1;
	}
	cout<<ans<<endl;
	return 0;
}