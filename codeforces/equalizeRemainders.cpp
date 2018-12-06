#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> nextRequired(200005,-1);
ll n,m;

ll next(ll x)
{
	if(nextRequired[x]==-1 || nextRequired[x]==x)
		return x;
	if(nextRequired[x]==m)
	{
		nextRequired[x]=0;
		return 0;
	}
	nextRequired[x]=next(nextRequired[x]);
	return nextRequired[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	vector<ll> a;
	vector<ll> cnt(200005,0);
	vector<pii> increase(200005);
	ll i,val;
	ll ans=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		cnt[val%m]++;
	}
	for(i=0;i<m;i++)
	{
		if(cnt[i]>=n/m)
			nextRequired[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		ll rem=a[i]%m;
		if(cnt[rem]>n/m)
		{
			ll nxt=next(rem);
			a[i]+=((nxt-rem+m)%m);
			ans+=((nxt-rem+m)%m);
			cnt[rem]--;
			cnt[nxt]++;
			if(cnt[nxt]==n/m)
				nextRequired[nxt]=nxt+1;
		}
	}
	cout<<ans<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}