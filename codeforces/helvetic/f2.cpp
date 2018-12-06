#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=200005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll colorr[200005];
	ll i;
	for(i=0;i<n;i++)
		cin>>colorr[i];
	ll required[200005];
	ll sum=0;
	for(i=1;i<=m;i++)
	{
		cin>>required[i];
		sum+=required[i];
	}
	ll got[200005]={0};
	ll j=1;
	for(i=0;i<n;i++)
	{
		while(got[j]>=required[j] && j<=m)
			j++;
		if(j==m+1)
			break;
		got[colorr[i]]++;
	}
	while(got[j]>=required[j] && j<=m)
		j++;
	if(j!=m+1)
	{
		cout<<"-1\n";
		return 0;
	}
	ll now=i;
	ll ans=now-sum;
	ll t;
	j=i;
	for(t=0;t<n;t++)
	{
		got[colorr[t]]--;
		now--;
		while(got[colorr[t]]<required[colorr[t]] && j<n)
		{
			got[colorr[j]]++;
			now++;
			j++;
		}
		if(got[colorr[t]]>=required[colorr[t]])
			ans=min(ans,now-sum);
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}