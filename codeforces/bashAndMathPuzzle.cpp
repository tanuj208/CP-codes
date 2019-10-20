#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> segTree(2000006,0);
vector<ll> a;
ll cnt=0;

void makeTree(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[i]=a[s];
		return;
	}
	ll m=(s+e)/2;
	makeTree(s,m,(i<<1));
	makeTree(m+1,e,(i<<1)+1);
	segTree[i] = __gcd(segTree[(i<<1)], segTree[(i<<1)+1]);
	return;
}

ll calcGcd(ll s,ll e,ll i,ll l,ll r)
{
	if(e<l || s>r)
		return 0;
	if(s>=l && e<=r)
		return segTree[i];
	ll m=(s+e)/2;
	return __gcd(calcGcd(s,m,(i<<1),l,r), calcGcd(m+1,e,(i<<1)+1,l,r));
}

void update(ll s,ll e,ll i,ll x,ll y)
{
	if(s==e && s==x)
	{
		segTree[i]=y;
		return;
	}
	if(x<s || x>e)
		return;
	ll m=(s+e)/2;
	update(s,m,(i<<1),x,y);
	update(m+1,e,(i<<1)+1,x,y);
	segTree[i]=__gcd(segTree[(i<<1)],segTree[(i<<1)+1]);
	return;
}

bool query(ll s,ll e,ll i,ll l,ll r,ll x)
{
	if(s==e && l<=s && e>=s)
	{
		if(segTree[i]%x!=0)
			cnt++;
		return true;
	}
	if(e<l || s>r)
		return true;
	if(s>=l && e<=r)
		if(segTree[i]%x==0)
			return true;
	ll m=(s+e)/2;
	ll x1=calcGcd(s,m,(i<<1),l,r);
	ll x2=calcGcd(m+1,e,(i<<1)+1,l,r);
	if(x1%x!=0 && x2%x!=0)
	{
		cnt+=2;
		return false;
	}
	if(x1%x==0 && x2%x==0)
		return true;
	if(x1%x!=0)
		return query(s,m,(i<<1),l,r,x);
	else
		return query(m+1,e,(i<<1)+1,l,r,x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i,val;
	ll q;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	makeTree(0,n-1,1);
	cin>>q;
	while(q--)
	{
		cnt=0;
		ll aa;
		cin>>aa;
		if(aa==1)
		{
			ll l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			bool tmp=query(0,n-1,1,l,r,x);
			if(cnt<=1)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
		{
			ll x,y;
			cin>>x>>y;
			x--;
			update(0,n-1,1,x,y);
		}
	}
	return 0;
}