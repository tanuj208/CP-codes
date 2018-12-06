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
	ll n,a,b,c,t;
	cin>>n>>a>>b>>c>>t;
	ll i,time[10006];
	for(i=0;i<n;i++)
		cin>>time[i];
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(c>b)
			ans+=(a+(c-b)*(t-time[i]));
		else
			ans+=a;
	}
	cout<<ans<<endl;
	return 0;
}