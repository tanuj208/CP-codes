#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;
map<ll,ll> dp;

void rec(ll x)
{
	if(dp.find(x-1)!=dp.end())
	{
		ll temp=dp[x-1]+1;
		if(dp.find(x)!=dp.end())
			temp=max(temp,dp[x]);
		dp[x]=temp;
	}
	else if(dp.find(x)==dp.end())
		dp.insert(mp(x,1));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		rec(val);
	}
	ll ind;
	ll ans=0;
	for(auto it=dp.begin();it!=dp.end();it++)
	{
		ll temp=(*it).second;
		if(temp>ans)
		{
			ind=(*it).first;
			ans=temp;
		}
	}
	vector<ll> aa;
	for(i=n-1;i>=0;i--)
	{
		if(a[i]==ind)
		{
			aa.pb(i+1);
			ind--;
		}
	}
	reverse(aa.begin(),aa.end());
	cout<<ans<<endl;
	for(i=0;i<ans;i++)
		cout<<aa[i]<<" ";
	cout<<endl;
	return 0;
}