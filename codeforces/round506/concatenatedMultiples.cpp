#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll digits(ll x)
{
	ll ans=0;
	while(x!=0)
		ans++,x/=10;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll i,val;
	vector<ll> a;
	map<ll,ll> l[11];
	vector<ll> p;
	p.pb(1);
	for(i=0;i<10;i++)
		p.pb(p[i]*10);
	for(i=0;i<=10;i++)
		p[i]%=k;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		val %= k;
		for(ll j=0;j<=10;j++)
			l[j][(p[j]*val)%k]++;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ll x=a[i]%k;
		x = k-x;
		x%=k;
		ll d = digits(a[i]);
		if(l[d].find(x)!=l[d].end())
			ans+=l[d][x];
		if(((a[i]%k)*(p[d]))%k==x)
			ans--;
	}
	cout<<ans<<"\n";
	return 0;
}