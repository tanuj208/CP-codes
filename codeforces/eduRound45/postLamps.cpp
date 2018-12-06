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
	vector<ll> prevEmpty(1000006,-1);
	vector<ll> blocked(1000006,0);
	ll n,m,k;
	cin>>n>>m>>k;
	ll i,val;
	for(i=0;i<m;i++)
	{
		cin>>val;
		blocked[val]=1;
	}
	ll xx=0;
	for(i=0;i<=n;i++)
	{
		if(blocked[i]==0)
			xx=i;
		prevEmpty[i]=xx;
	}
	vector<ll> costt;
	for(i=0;i<k;i++)
	{
		cin>>val;
		costt.pb(val);
	}
	if(blocked[0]==1)
	{
		cout<<"-1\n";
		return 0;
	}
	ll finalCost=LLONG_MAX;
	for(i=1;i<=k;i++)
	{
		ll lamps=1;
		ll j=i;
		ll prevj=0;
		ll ff=0;
		while(j<n)
		{
			j=prevEmpty[j];
			if(j<=prevj)
			{
				ff=1;
				break;
			}
			lamps++;
			prevj=j;
			j+=i;
		}
		if(ff==0)
			finalCost=min(finalCost,lamps*costt[i-1]);
	}
	if(finalCost>=100000000000000)
		cout<<"-1\n";
	else
		cout<<finalCost<<endl;
	return 0;
}