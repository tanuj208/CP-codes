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
	ll ans=0,i;
	vector<ll> flag(1000005,0),pre(1000005,0);
	for(i=1;i<sz(s);i++)
	{
		ll x=pre[i-1];
		while(s[x]!=s[i] && x!=0)
			x=pre[x-1];
		if(s[x]==s[i])
			pre[i]=x+1;
		x=pre[i];
		while(flag[x]!=1 && x!=0)
			x=pre[x-1];
		if(flag[x]==1)
			ans+=x;
		flag[pre[i]]=1;
	}
	cout<<ans<<endl;
	return 0;
}