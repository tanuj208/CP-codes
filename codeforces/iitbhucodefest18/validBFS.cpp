#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

set<ll> ad[200005];
vector<ll> l(200005,0);

void dfs(ll v,ll p)
{
	ll i;
	for(auto it=ad[v].begin();it!=ad[v].end();it++)
	{
		ll x=*it;
		if(x==p)
			continue;
		l[x]=l[v]+1;
		dfs(x,v);
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
	for(i=1;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		ad[a].insert(b);
		ad[b].insert(a);
	}
	dfs(1,0);
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	ll last=l[a[0]];
	for(i=1;i<n;i++)
	{
		if(l[a[i]]<last)
		{
			cout<<"No\n";
			return 0;
		}
		last=l[a[i]];
	}
	last = 0;
	ll cnt[200005]={0};
	for(i=1;i<n;i++)
	{
		ll x = a[i];
		ll y = a[last];
		if(ad[y].find(x)==ad[y].end())
		{
			cout<<"No\n";
			return 0;
		}
		else
			cnt[y]++;
		if(cnt[y]==sz(ad[y]) && y==1)
		{
			last++;
			y = a[last];
		}
		while(cnt[y]==sz(ad[y])-1 && y!=1 && last<i)
		{
			last++; 
			y=a[last];
		}
	}
	cout<<"Yes\n";
	return 0;
}