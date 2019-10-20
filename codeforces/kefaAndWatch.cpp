#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,mm,k;
ll b=37;
vector<ll> a;
vector<ll> arr(100005,1);
vector<ll> segTree(400006,0);
vector<ll> lazy(400006,0);

void makeSegTree(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[i]=a[s];
		return;
	}
	ll m=(s+e)/2;
	makeSegTree(s,m,(i<<1));
	makeSegTree(m+1,e,(i<<1)+1);
	segTree[i]=(segTree[(i<<1)]+(arr[m-s+1]*segTree[(i<<1)+1])%mod)%mod;
	return;
}

ll divisionMod(ll aa, ll bb)
{
	ll val=1;
	ll power=mod-2;
	while(power!=0)
	{
		if(power%2==1)
			val=(val*bb)%mod;
		bb=bb*bb;
		bb=bb%mod;
		power=power/2;
	}
	return (aa*val)%mod;
}

void update(ll s,ll e,ll i,ll l,ll r,ll x)
{
	if(s>r || l>e)
		return;
	if(l<=s && r>=e)
	{
		segTree[i]=divisionMod((x*(arr[e-s+1]-1))%mod,b-1);
		lazy[(i<<1)]=x;
		lazy[(i<<1)+1]=x;
		return;
	}
	ll m=(s+e)/2;
	update(s,m,(i<<1),l,r,x);
	update(m+1,e,(i<<1)+1,l,r,x);
	segTree[i]=(segTree[(i<<1)]+(arr[m-s+1]*segTree[(i<<1)+1])%mod)%mod;
	return;
}

ll query(ll s,ll e,ll i,ll l,ll r)
{
	if(s>r || l>e)
		return 0;
	if(l<=s && r>=e)
	{
		if(lazy[i]!=0)
			segTree[i]=divisionMod((lazy[i]*(arr[e-s+1]-1))%mod,b-1);
		lazy[(i<<1)]=lazy[i];
		lazy[(i<<1)+1]=lazy[i];
		lazy[i]=0;
		return segTree[i];
	}
	ll m=(s+e)/2;
	lazy[(i<<1)]+=lazy[i];
	lazy[(i<<1)+1]+=lazy[i];
	if(lazy[i]!=0)
		segTree[i]=divisionMod((lazy[i]*(arr[e-s+1]-1))%mod,b-1);
	lazy[i]=0;
	ll q1=query(s,m,(i<<1),l,r);
	ll q2=query(m+1,e,(i<<1)+1,l,r);
	ll el;
	if(l>s)
		el=m-l+1;
	else
		el=m-s+1;
	if(el<0 || r<m)
		el=0;
	return (q1+(arr[el]*q2)%mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>mm>>k;
	string s;
	cin>>s;
	ll i,val;
	for(i=0;i<n;i++)
		a.pb(s[i]-'0');
	for(i=1;i<=100000;i++)
		arr[i]=(arr[i-1]*b)%mod;
	makeSegTree(0,n-1,1);
	ll q=mm+k;
	while(q--)
	{
		ll w,l,r,c;
		cin>>w>>l>>r>>c;
		l--;
		r--;
		if(w==1)
			update(0,n-1,1,l,r,c);
		else
		{
			if(l>r-c || l+c>r)
			{
				cout<<"YES\n";
				continue;
			}
			ll x1=query(0,n-1,1,l,r-c);
			ll x2=query(0,n-1,1,l+c,r);
			if(x1==x2)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}