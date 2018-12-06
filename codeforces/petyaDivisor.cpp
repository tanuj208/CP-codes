#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> divisors[100005];

void preprocessing()
{
	ll i,j;
	for(i=1;i<=100000;i++)
		for(j=i;j<=100000;j+=i)
			divisors[j].pb(i);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll last[100005]={0};
	ll i;
	preprocessing();
	for(i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(y==0)
			cout<<sz(divisors[x])<<"\n";
		else
		{
			ll ans=0;
			for(ll j=0;j<sz(divisors[x]);j++)
				if(last[divisors[x][j]]<i-y)
					ans++;
			cout<<ans<<"\n";
		}
		for(ll j=0;j<sz(divisors[x]);j++)
			last[divisors[x][j]]=i;
	}
	return 0;
}