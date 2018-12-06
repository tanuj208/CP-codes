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
	string s,x;
	cin>>s>>x;
	ll ones=0;
	ll i;
	ll zeros=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
			zeros++;
		else
			ones++;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0' && x[i]=='0')
		{
			ans+=ones;
			zeros--;
		}
		else if(s[i]=='1' && x[i]=='0')
		{
			ans+=zeros;
			ones--;
		}
	}
	cout<<ans<<endl;
	return 0;
}