#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	ll i,j;
	cin>>n>>m;
	vector<p> wts[500005];
	for(i=0;i<m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		wts[w].pb(mp(u,v));
	}
	ll dp[500005]={0};
	vector<ll> temp(500005);
	for(i=1;i<500005;i++)
	{
		for(j=0;j<sz(wts[i]);j++)
		{
			ll v2=wts[i][j].second;
			temp[v2]=0;
		}
		for(j=0;j<sz(wts[i]);j++)
		{
			ll v1=wts[i][j].first;
			ll v2=wts[i][j].second;
			temp[v2]=max(1+dp[v1],temp[v2]);
		}
		for(j=0;j<sz(wts[i]);j++)
		{
			ll v2=wts[i][j].second;
			dp[v2]=max(dp[v2],temp[v2]);
		}
	}
	ll ans=0;
	for(i=1;i<=500005;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}