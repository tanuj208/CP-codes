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
	ll n,k,m;
	cin>>n>>k>>m;
	map<string,ll> words;
	ll i;
	vector<string> temp;
	for(i=0;i<n;i++)
	{
		string tempp;
		cin>>tempp;
		temp.pb(tempp);
	}
	vector<ll> cost;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		cost.pb(val);
		// words.insert(mp(temp[i],val));
	}
	ll j;
	ll mincost;
	for(i=0;i<k;i++)
	{
		mincost=INT_MAX;
		ll x;
		cin>>x;
		vector<ll> temparr;
		for(j=0;j<x;j++)
		{
			ll val;
			cin>>val;
			temparr.pb(val);
			mincost=min(mincost,cost[val-1]);
		}
		for(j=0;j<x;j++)
			cost[temparr[j]-1]=mincost;
	}
	for(i=0;i<n;i++)
		words.insert(mp(temp[i],cost[i]));
	ll ans=0;
	for(i=0;i<m;i++)
	{
		string a;
		cin>>a;
		ans+=words[a];
	}
	cout<<ans<<endl;
	return 0;
}