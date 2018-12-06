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
	ll n;
	cin>>n;
	vector<ll> p;
	ll i,val;
	p.pb(-1);
	for(i=0;i<n;i++)
	{
		cin>>val;
		p.pb(val);
	}
	ll j;
	for(i=1;i<=n;i++)
	{
		ll hole[1004]={0};
		hole[i]=1;
		ll x=p[i];
		while(hole[x]==0)
		{
			hole[x]=1;
			x=p[x];
		}
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}