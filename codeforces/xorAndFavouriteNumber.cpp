#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,m,k;
vector<ll> cnt(2000005,0);
vector<ll> a;
vector<ll> ans(100005);
vector<ll> cum(100005,0);
ll anss=0;

void add(ll x)
{
	anss+=cnt[k^x];
	cnt[x]++;
	return;
}

void remove(ll x)
{
	cnt[x]--;
	anss-=cnt[k^x];
	return;
}

bool cmp(pair<pii,ll> a,pair<pii,ll> b)
{
	return a.first.second<b.first.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	ll i,val;
	cum[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>val;
		a.pb(val);
		cum[i]=cum[i-1]^val;
	}
	vector<pair<pii,ll> > q[320];
	for(i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r;
		l--,r++;
		q[l/(ll)316].pb(mp(mp(l,r),i));
	}
	for(i=0;i<=316;i++)
		sort(q[i].begin(),q[i].end(),cmp);
	for(i=0;i<=316;i++)
	{
		ll curl=i*316;
		ll curr=i*316;
		for(ll j=0;j<sz(q[i]);j++)
		{
			ll l=q[i][j].first.first;
			ll r=q[i][j].first.second;
			ll ind=q[i][j].second;
			while(curr<r)
			{
				add(cum[curr]);
				curr++;
			}
			while(curl<l)
			{
				remove(cum[curl]);
				curl++;
			}
			while(curl>l)
			{
				curl--;
				add(cum[curl]);
			}
			ans[ind]=anss;
		}
		for(ll j=curl;j<curr;j++)
			remove(cum[j]);
	}
	for(i=0;i<m;i++)
		cout<<ans[i]<<"\n";
	return 0;
}