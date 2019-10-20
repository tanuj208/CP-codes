#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool isSquare(ll x)
{
	ll a=sqrt(x);
	if(a*a==x)
		return true;
	else
		return false;
}

vector<ll> segTree(400005,0);

void reset(ll n)
{
	ll i;
	for(i=0;i<=4*n+1;i++)
		segTree[i]=0;
	return;
}

void update(ll s,ll e,ll i,ll l,ll r1,ll r2)
{
	if(s==e)
	{
		if(e>=r1 && e<=r2)
			segTree[i]++;
		return;
	}
	if(e<r1)
		return;
	segTree[i]+=min(e,r2)-r1+1;
	ll m=(s+e)/2;
	if(l<=m)
		update(s,m,(i<<1),l,r1,r2);
	else
		update(m+1,e,(i<<1)+1,l,r1,r2);
	return;
}

ll query(ll s,ll e,ll i,ll l,ll r)
{
	if(r<s || l>e)
		return 0;
	if(s<=l && e>=r)
		return segTree[i];
	ll m=(l+r)/2;
	return query(s,m,(i<<1),l,r)+query(m+1,e,(i<<1)+1,l,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll i,j;
	vector<ll> pp;
	pp.pb(1);
	for(i=0;i<30;i++)
		pp.pb(2*pp[i]);
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		reset(n);
		ll firstzero[n+1][32];
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		for(i=n-1;i>=0;i--)
		{
			ll x=a[i];
			ll j=0;
			while(x!=0)
			{
				if(x%2==0)
					firstzero[i][j]=i;
				else
				{
					if(i==n-1)
						firstzero[i][j]=10000000000;
					else
						firstzero[i][j]=firstzero[i+1][j];
				}
				x/=2;
				j++;
			}
			for(;j<30;j++)
				firstzero[i][j]=i;
		}
		for(i=0;i<n;i++)
		{
			vector<pii> tmp;
			for(ll j=0;j<30;j++)
				tmp.pb(mp(firstzero[i][j],j));
			sort(tmp.begin(),tmp.end());
			vector<ll> bitt(30,0);
			ll x=a[i];
			while(x!=0)
			{
				bitt.pb(x%2);
				x/=2;
			}
			if(tmp[0].first>100000000)
			{
				if(isSquare(x))
					update(0,n-1,1,i,i,i);
				continue;
			}
			ll ind2;
			ll ind1=i;
			for(j=0;j<30;j++)
			{
				if(tmp[j].first>10000000)
					break;
				if(tmp[j].first==i)
					continue;
				if(j==0 || tmp[j].first!=tmp[j-1].first)
				{
					ind2=tmp[j].first-1;
					ll num=0;
					for(ll kk=0;kk<30;kk++)
						if(bitt[kk]==1)
							num+=pp[kk];
					cout<<i<<" "<<ind1<<" "<<ind2<<" "<<num<<endl;
					if(isSquare(num))
						update(0,n-1,1,i,ind1,ind2);
					ind1=tmp[j].first;
				}
				bitt[tmp[j].second]=0;
			}
		}
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			cout<<query(0,n-1,1,l-1,r-1)<<"\n";
		}
	}
	return 0;
}