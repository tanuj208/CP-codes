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
	ll n,x,y;
	cin>>n>>x>>y;
	ll bunches=0;
	string s;
	ll i;
	cin>>s;
	if(s[0]=='0')
		bunches++;
	for(i=1;i<n;i++)
	{
		if(s[i]=='0' && s[i-1]=='1')
			bunches++;
	}
	if(bunches==0)
	{
		cout<<"0\n";
		return 0;
	}
	ll ans=LLONG_MAX;
	for(i=bunches;i>=1;i--)
		ans=min(ans,i*y+(bunches-i)*x);
	cout<<ans<<endl;
	return 0;
}