#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> dp[200005];
vector<ll> segTree[1000005];

vector<ll> merge(vector<ll> a,vector<ll> b)
{
	ll i=0,j=0;
	vector<ll> c;
	while(i<sz(a) && j<sz(b))
	{
		if(a[i]<=b[j])
			c.pb(a[i]),i++;
		else
			c.pb(b[j]),j++;
	}
	while(i<sz(a))
		c.pb(a[i]),i++;
	while(j<sz(b))
		c.pb(b[j]),j++;
	return c;
}

void build(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[i]=dp[s];
		return;
	}
	ll m=(s+e)/2;
	build(s,m,(i<<1));
	build(m+1,e,(i<<1)+1);
	segTree[i]=merge(segTree[(i<<1)],segTree[(i<<1)+1]);
	return;
}

ll query(ll s,ll e,ll i,ll l,ll r,ll x)
{
	if(l>e || r<s)
		return 0;
	if(l<=s && e<=r)
		return upper_bound(segTree[i].begin(),segTree[i].end(),x)-segTree[i].begin();
	ll m=(s+e)/2;
	ll q1=query(s,m,(i<<1),l,r,x);
	ll q2=query(m+1,e,(i<<1)+1,l,r,x);
	return q1+q2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<ll> a(200005);
	ll xx=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=i)
			xx++;
		if(a[i]>n)
			a[i]=n;
		dp[a[i]].pb(i);
	}
	for(i=1;i<=n;i++)
		sort(dp[i].begin(),dp[i].end());
	build(1,n,1);
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=query(1,n,1,i,n,a[i]);
	ans-=xx;
	ans/=2;
	cout<<ans<<endl;
	return 0;
}