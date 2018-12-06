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
	cin>>s;
	ll i;
	for(i=1;i<sz(s)-1;i++)
	{
		if(s[i]=='.' || s[i-1]=='.' || s[i+1]=='.')
			continue;
		if(s[i]!=s[i+1] && s[i]!=s[i-1] && s[i-1]!=s[i+1])
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}