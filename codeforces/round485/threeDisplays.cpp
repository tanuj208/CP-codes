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
	vector<ll> s;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		s.pb(val);
	}
	vector<ll> c;
	for(i=0;i<n;i++)
	{
		cin>>val;
		c.pb(val);
	}
	vector<ll> dp(3005,0); // dp[i] contains lcds with greater fonts
	ll j;
	for(i=0;i<n;i++)
	{
		ll x=LLONG_MAX;
		for(j=i+1;j<n;j++)
		{
			if(s[j]>s[i])
				x=min(x,c[j]);
		}
		dp[i]=x;
	}
	ll ans=LLONG_MAX;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ll x=c[i];
			if(s[j]>s[i] && dp[j]!=LLONG_MAX)
				x=x+c[j]+dp[j];
			else
				x=LLONG_MAX;
			ans=min(ans,x);
		}
	}
	if(ans==LLONG_MAX)
		cout<<"-1\n";
	else
		cout<<ans<<endl;
	return 0;
}