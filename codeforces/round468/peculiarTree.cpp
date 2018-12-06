#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp make_pair
#define pb push_back
#define sz(a) (int)(a).size()

vector<ll> ad[100005];

ll ans=0;
ll app[100004]={0};

void dfs(ll i)
{
	if(sz(dfs[i])%2!=0)
		ans++;
	ll j;
	for(j=0;j<sz(dfs[i]);j++)
	{
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	cin>>n;
	ll val;
	for(i=2;i<=n;i++)
	{
		cin>>val;
		ad[val].pb(i);
	}
	// for(i=1;i<=n;i++)
	// {
	// 	cout<<xx[i].first<<" "<<xx[i].second<<endl;
	// }
	return 0;
}