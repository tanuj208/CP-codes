#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> divi(1000005,2);
vector<ll> addSeg(1200005,0);
vector<ll> maxSeg(1200005,0);
vector<ll> a;
ll n;

void makeSeg(ll s,ll e,ll i)
{
	if(s==e)
	{
		addSeg[i]=a[s];
		maxSeg[i]=a[s];
		return;
	}
	ll m=(s+e)/2;
	makeSeg(s,m,(i<<1));
	makeSeg(m+1,e,(i<<1)+1);
	addSeg[i]=addSeg[(i<<1)]+addSeg[(i<<1)+1];
	maxSeg[i]=max(maxSeg[(i<<1)],maxSeg[(i<<1)+1]);
	return;
}

ll query(ll s,ll e,ll i,ll l,ll r)
{
	if(s>r || e<l)
		return 0;
	if(s>=l && e<=r)
		return addSeg[i];
	ll m=(s+e)/2;
	ll x1=query(s,m,(i<<1),l,r);
	ll x2=query(m+1,e,(i<<1)+1,l,r);
	return x1+x2;
}

ll querymax(ll s,ll e,ll i,ll l,ll r)
{
	if(s>r || e<l)
		return 0;
	if(s>=l && e<=r)
		return maxSeg[i];
	ll m=(s+e)/2;
	ll x1=querymax(s,m,(i<<1),l,r);
	ll x2=querymax(m+1,e,(i<<1)+1,l,r);
	return max(x1,x2);
}

void update(ll s,ll e,ll i,ll l,ll r)
{
	if(s>r || e<l)
		return;
	if(s>=l && e<=r)
	{
		ll x=querymax(0,n-1,1,s,e);
		if(x<=2)
			return;
		ll j;
		for(j=s;j<=e;j++)
			a[j]=divi[a[j]];
		makeSeg(s,e,i);
		return;
	}
	ll m=(s+e)/2;
	update(s,m,(i<<1),l,r);
	update(m+1,e,(i<<1)+1,l,r);
	addSeg[i]=addSeg[(i<<1)]+addSeg[(i<<1)+1];
	maxSeg[i]=max(maxSeg[(i<<1)],maxSeg[(i<<1)+1]);
	return;
}

void numDiv()
{
	divi[1]=1;
	ll i,j;
	for(i=2;i<=1000000;i++)
		for(j=2*i;j<=1000000;j+=i)
			divi[j]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll m;
	cin>>n>>m;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	numDiv();
	makeSeg(0,n-1,1);
	while(m--)
	{
		ll t,l,r;
		cin>>t>>l>>r;
		if(t==1)
			update(0,n-1,1,l-1,r-1);
		else
			cout<<query(0,n-1,1,l-1,r-1)<<"\n";
	}
	return 0;
}