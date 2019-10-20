#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pii> ans;
vector<ll> tmp(400005,0);
vector<ll> dd(400005,0);
vector<ll> xxx;
ll v;
ll n,d,k;
ll degree=2;

void printAns()
{
	ll i;
	cout<<"YES\n";
	for(i=0;i<sz(ans);i++)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}

bool recmake(ll x)
{
	while(dd[x]!=degree)
	{
		if(tmp[x]==0)
			break;
		v++;
		dd[x]++;
		dd[v]++;
		ans.pb(mp(x,v));
		if(v==n)
		{
			printAns();
			return true;
		}
		tmp[v]=tmp[x]-1;
		if(tmp[v]!=0)
			xxx.pb(v);
		dd[v]=1;
		bool xx=recmake(v);
		if(xx==true)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>d>>k;
	ll i;
	if(d>=n)
	{
		cout<<"NO\n";
		return 0;
	}
	if(n==1)
	{
		cout<<"YES\n";
		return 0;
	}
	if(n==2)
	{
		cout<<"YES\n";
		cout<<"1 2\n";
		return 0;
	}
	if(k==1)
	{
		cout<<"NO\n";
		return 0;
	}
	dd[1]=2;
	for(i=1;i<=d;i++)
	{
		xxx.pb(i);
		ans.pb(mp(i,i+1));
		tmp[i]=min(i-1,d+1-i);
		dd[i+1]=2;
	}
	xxx.pb(d+1);
	dd[v]=1;
	v=d+1;
	if(v==n)
	{
		printAns();
		return 0;
	}
	while(true)
	{
		degree++;
		if(degree>k)
		{
			cout<<"NO\n";
			return 0;
		}
		ll tmpp=v;
		for(i=0;i<sz(xxx);i++)
		{
			ll tt=xxx[i];
			bool xx=recmake(tt);
			if(xx==true)
				return 0;
		}
	}
	return 0;
}