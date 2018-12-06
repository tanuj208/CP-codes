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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll i,val;
		ll ans=0;
		ll cnt=0;
		vector<ll> pp(31,1);
		for(i=1;i<=30;i++)
			pp[i]=pp[i-1]*2;
		for(i=0;i<n;i++)
		{
			cin>>val;
			if(val%m==0)
				cnt++;
		}
		ans+=(pp[cnt]-1);
		cout<<ans<<"\n";
	}
	return 0;
}