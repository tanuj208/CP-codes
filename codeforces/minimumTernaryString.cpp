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
	string s;
	string ans;
	cin>>s;
	ll z=0,o=0;
	ll i;
	for(i=0;i<sz(s);i++)
		if(s[i]=='1')
			o++;
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='0')
			z++;
		else if(s[i]=='2')
			break;
	}
	ll ind=i+1;
	for(i=0;i<z;i++)
		ans.pb('0');
	for(i=0;i<o;i++)
		ans.pb('1');
	z=0;
	if(ind<=sz(s))
		ans.pb('2');
	for(i=ind;i<sz(s);i++)
	{
		if(s[i]=='0')
			z++;
		else if(s[i]=='2')
		{
			for(ll j=0;j<z;j++)
				ans.pb('0');
			z=0;
			ans.pb('2');
		}
	}
	while(sz(ans)<sz(s))
		ans.pb('0');
	for(i=0;i<sz(ans);i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}