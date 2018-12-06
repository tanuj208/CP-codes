#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll ans=0;
ll x;
ll n,m;
vector<ll> a,b;
ll aa[2005][2005];
ll bb[2005][2005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i,j;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<m;i++)
	{
		ll val;
		cin>>val;
		b.pb(val);
	}
	cin>>x;
	for(i=0;i<n;i++)
	{
		aa[i][i]=a[i];
		for(j=i+1;j<m;j++)
			aa[i][j]=aa[i][j-1]+a[j];
	}
	return 0;
}