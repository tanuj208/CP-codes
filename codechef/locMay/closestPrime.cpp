#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<bool> isPrime(300005);
vector<bool> tmp(200005);

void sieve(ll m)
{
	ll i;
	for(i=2;i<=200000;i++)
		tmp[i]=true;
	for(i=0;i<=300000;i++)
		isPrime[i]=true;
	tmp[1]=false;
	for(i=2;i<=200000;i++)
	{
		if(tmp[i])
		{
			for(ll j=2*i;j<=200000;j+=i)
				tmp[j]=false;
			ll x=m%i;
			if(x==0)
				x=i;
			for(ll j=i-x;j<=300000;j+=i)
			{
				if(j+m==i)
					continue;
				isPrime[j]=false;
			}
		}
	}
	return;
}

vector<ll> sumSeg(500005,0);
vector<ll> maxSeg(500005,0);
vector<ll> a;
vector<ll> replsmall(200005,0);
vector<ll> repllarge(300005,0);
ll n;
ll m=LLONG_MAX;

void makeSeg(ll s,ll e,ll i)
{
	if(s==e)
	{
		sumSeg[i]=a[s];
		maxSeg[i]=a[s];
		return;
	}
	ll m=(s+e)/2;
	makeSeg(s,m,(i<<1));
	makeSeg(m+1,e,(i<<1)+1);
	sumSeg[i]=sumSeg[(i<<1)]+sumSeg[(i<<1)+1];
	maxSeg[i]=max(maxSeg[(i<<1)],maxSeg[(i<<1)+1]);
	return;
}

ll queryMax(ll s,ll e,ll i,ll l,ll r)
{
	if(r<s || l>e)
		return 0;
	if(s>=l && r>=e)
		return maxSeg[i];
	ll m=(s+e)/2;
	ll q1=queryMax(s,m,(i<<1),l,r);
	ll q2=queryMax(m+1,e,(i<<1)+1,l,r);
	return max(q1,q2);
}

void makeSegAgain(ll s,ll e,ll i)
{
	if(s==e)
	{
		sumSeg[i]=a[s];
		maxSeg[i]=a[s];
		return;
	}
	ll m=(s+e)/2;
	ll q1=queryMax(0,n-1,1,s,m);
	if(q1>2)
		makeSeg(s,m,(i<<1));

	ll q2=queryMax(0,n-1,1,m+1,e);
	if(q2>2)
		makeSeg(m+1,e,(i<<1)+1);
	sumSeg[i]=sumSeg[(i<<1)]+sumSeg[(i<<1)+1];
	maxSeg[i]=max(maxSeg[(i<<1)],maxSeg[(i<<1)+1]);
	return;
}
ll querySum(ll s,ll e,ll i,ll l,ll r)
{
	if(r<s || l>e)
		return 0;
	if(s>=l && r>=e)
		return sumSeg[i];
	ll m=(s+e)/2;
	ll q1=querySum(s,m,(i<<1),l,r);
	ll q2=querySum(m+1,e,(i<<1)+1,l,r);
	return q1+q2;
}

void update(ll s,ll e,ll i,ll l,ll r)
{
	if(r<s || l>e)
		return;
	if(s>=l && r>=e)
	{
		ll q=queryMax(0,n-1,1,s,e);
		if(q<=2)
			return;
		ll j;
		for(j=s;j<=e;j++)
		{
			ll val=a[j];
			if(val<=200000)
				a[j]=replsmall[val];
			else
				a[j]=repllarge[val-m];
		}
		makeSegAgain(s,e,i);
		return;
	}
	ll m=(s+e)/2;
	update(s,m,(i<<1),l,r);
	update(m+1,e,(i<<1)+1,l,r);
	sumSeg[i]=sumSeg[(i<<1)]+sumSeg[(i<<1)+1];
	maxSeg[i]=max(maxSeg[(i<<1)],maxSeg[(i<<1)+1]);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin>>n>>q;
	ll i,val;
	vector<pii> tmpp;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		m=min(m,val);
	}
	if(m>=100000)
		m-=100000;
	sieve(m);
	if(m<100000)
	{
		isPrime=tmp;
		m=0;
	}
	makeSeg(0,n-1,1);
	ll prr;
	replsmall[0]=0;
	replsmall[1]=1;
	replsmall[2]=2;
	for(i=3;i<=200000;i++)
	{
		replsmall[i]=i-prr;
		if(tmp[i])
			prr=i;
	}
	if(m>100000)
	{
		for(i=0;i<=300000;i++)
		{
			repllarge[i]=i-prr;
			if(isPrime[i])
				prr=i;
		}
	}

	while(q--)
	{
		ll t,l,r;
		cin>>t>>l>>r;
		if(t==1)
			update(0,n-1,1,l-1,r-1);
		else
			cout<<querySum(0,n-1,1,l-1,r-1)<<"\n";
	}
	return 0;
}