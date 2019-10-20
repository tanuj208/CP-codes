#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> nextUndefeated(300005,0);
ll ans[300005];

ll next(ll x)
{
	if(nextUndefeated[x]==0)
		return x;
	nextUndefeated[x]=next(nextUndefeated[x]);
	return nextUndefeated[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,i,w;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r>>w;
		ll j;
		for(j=l;j<=r;j++)
		{
			j=next(j);
			if(j==w || j>r)
				continue;
			ans[j]=w;
			nextUndefeated[j]=j+1;
		}
	}
	ans[w]=0;
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}