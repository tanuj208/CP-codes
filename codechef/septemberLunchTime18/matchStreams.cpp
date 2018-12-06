#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<ll> addSeg(500005,0);
vector<ll> lazy(500005,0);
vector<ll> a,b;
vector<ll> segTree[500005];
ll n;

vector<ll> merge(vector<ll> a1, vector<ll> a2)
{
	ll i,j;
	vector<ll> temp;
	i=j=0;
	ll n1,n2;
	n1=sz(a1);
	n2=sz(a2);
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			temp.pb(a1[i]);
			i++;
		}
		else
		{
			temp.pb(a2[j]);
			j++;
		}
	}
	while(i<n1)
	{
		temp.pb(a1[i]);
		i++;
	}
	while(j<n2)
	{
		temp.pb(a2[j]);
		j++;
	}
	return temp;
}

void make_segTree(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[i].pb(b[s]);
		return;
	}
	ll m=(s+e)/2;
	make_segTree(s,m,(i<<1));
	make_segTree(m+1,e,(i<<1)+1);
	segTree[i]=merge(segTree[(i<<1)],segTree[(i<<1)+1]);
}

ll query(ll s,ll e,ll i,ll l,ll r,ll x) //from l to r equal to x
{
	if(r<s || l>e)
		return 0;
	if(l<=s && r>=e)
	{
		ll x1=upper_bound(segTree[i].begin(),segTree[i].end(),x)-segTree[i].begin();
		ll x2=lower_bound(segTree[i].begin(),segTree[i].end(),x)-segTree[i].begin();
		return x1-x2;
	}
	ll mid=(s+e)/2;
	ll q1=query(s,mid,(i<<1),l,r,x);
	ll q2=query(mid+1,e,(i<<1)+1,l,r,x);
	return q1+q2;
}

void update(ll s,ll e,ll i,ll l,ll r,ll c)
{
	if(r<s || l>e)
	{
		if(lazy[i]!=0)
		{
			lazy[(i<<1)]=lazy[i];
			lazy[(i<<1)+1]=lazy[i];
			addSeg[i]=query(0,n-1,1,s,e,lazy[i]);
			lazy[i]=0;
		}
		return;
	}
	if(l<=s && r>=e)
	{
		lazy[(i<<1)]=c;
		lazy[(i<<1)+1]=c;
		lazy[i]=0;
		addSeg[i]=query(0,n-1,1,s,e,c);
		return;
	}
	if(lazy[i]!=0)
	{
		lazy[(i<<1)]=lazy[i];
		lazy[(i<<1)+1]=lazy[i];
		lazy[i]=0;
	}
	ll m=(s+e)/2;
	update(s,m,(i<<1),l,r,c);
	update(m+1,e,(i<<1)+1,l,r,c);
	addSeg[i]=addSeg[(i<<1)]+addSeg[(i<<1)+1];
	return;
}

void make_addSeg(ll s,ll e,ll i)
{
	if(s==e)
	{
		if(a[s]==b[s])
			addSeg[i]=1;
		else
			addSeg[i]=0;
		return;
	}
	ll m=(s+e)/2;
	make_addSeg(s,m,(i<<1));
	make_addSeg(m+1,e,(i<<1)+1);
	addSeg[i]=addSeg[(i<<1)]+addSeg[(i<<1)+1];
}

void reset()
{
	ll i;
	for(i=0;i<=500000;i++)
	{
		segTree[i].clear();
		addSeg[i]=0;
		lazy[i]=0;	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		reset();
		ll q;
		cin>>n>>q;
		ll i,val;
		for(i=0;i<n;i++)
		{
			cin>>val;
			a.pb(val);
		}
		for(i=0;i<n;i++)
		{
			cin>>val;
			b.pb(val);
		}
		make_segTree(0,n-1,1);
		make_addSeg(0,n-1,1);
		while(q--)
		{
			ll x,y,z;
			cin>>x>>y>>z;
			ll pr=addSeg[1];
			ll l=x^pr;
			ll r=y^pr;
			ll c=z^pr;
			l--;
			r--;
			update(0,n-1,1,l,r,c);
			cout<<addSeg[1]<<"\n";
		}
	}
	return 0;
}