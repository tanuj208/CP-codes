#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll n,t;
ll mod=1000000007;
vector<ll> a(200005);
vector<ll> countt(1000005,0);
ll anss=0;
ll ss;

void incl(ll i)
{
	if(i>0 && i<=n)
	{
		ll x=a[i];
		anss+=(2*countt[x]+1)*x;
		countt[x]++;
	}
	return;
}

void rem(ll i)
{
	if(i>0 && i<=n)
	{
		ll x=a[i];
		anss-=(2*countt[x]-1)*x;
		countt[x]--;
	}
	return;
}

bool cmp(pair<pii,ll> q,pair<pii,ll> w)
{
	ll x1=q.first.second/ss+1;
	ll x2=w.first.second/ss+1;
	ll x3=q.first.first/ss+1;
	ll x4=w.first.first/ss+1;
	return (x1==x2)?(x3<x4):(x1<x2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>t;
	ll i,j;
	for(i=1;i<=n;i++)
		cin>>a[i];
	ss=ceil(sqrt(n));
	vector<pair<pii,ll> > root;
	for(i=0;i<t;i++)
	{
		ll l,r;
		cin>>l>>r;
		root.pb(mp(mp(r,l),i));
	}
	sort(root.begin(),root.end(),cmp);
	ll ans[200005];
	ll prevl=0;
	ll prevr=0;
	anss=0;
	for(i=0;i<t;i++)
	{
		ll l=root[i].first.second;
		ll r=root[i].first.first;
		ll ind=root[i].second;
		while(prevl>l)
			incl(--prevl);
		while(prevl<l)
			rem(prevl++);
		while(prevr>r)
			rem(prevr--);
		while(prevr<r)
			incl(++prevr);
		ans[ind]=anss;
	}
	for(i=0;i<t;i++)
		cout<<ans[i]<<"\n";
	return 0;
}