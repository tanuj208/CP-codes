#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

set<ll> pass;
vector<ll> val(100005);
vector<pii> ch(100005);

void dfs(ll v,ll mn,ll mx)
{
	if(val[v]<mn && val[v]>mx)
		pass.insert(val[v]);
	if(ch[v].first!=-1)
	{
		ll x=ch[v].first;
		dfs(x,min(mn,val[v]),mx);
	}
	if(ch[v].second!=-1)
	{
		ll x=ch[v].second;
		dfs(x,mn,max(mx,val[v]));
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	ll cnt[100005]={0};
	for(i=1;i<=n;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		if(b!=-1)
			cnt[b]=1;
		if(c!=-1)
			cnt[c]=1;
		val[i]=a;
		ch[i]=mp(b,c);
	}
	for(i=1;i<=n;i++)
		if(cnt[i]==0)
			break;
	dfs(i,LLONG_MAX,LLONG_MIN);
	ll ans=0;
	for(i=1;i<=n;i++)
		if(pass.find(val[i])==pass.end())
			ans++;
	cout<<ans<<endl;
	return 0;
}