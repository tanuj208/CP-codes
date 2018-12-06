#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,x;
	cin>>n>>x;
	if(n<x+1)
	{
		cout<<"-1\n";
		return 0;
	}
	ll cur=1;
	ll cnt=0;
	ll i;
	vector<ll> prim[2020],sec[2020];
	for(i=0;i<n;i++)
	{
		cnt=0;
		ll j;
		for(j=cur;j<=cur+x;j++)
			prim[i].pb(j);
		j=i+1;
		ll dest=cur+x;
		while(cur!=dest)
		{
			j%=n;
			sec[j].pb(cur);
			cur++;
			j++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(ll j=0;j<x;j++)
			cout<<prim[i][j]<<" ";
		for(ll j=0;j<x;j++)
			cout<<sec[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}