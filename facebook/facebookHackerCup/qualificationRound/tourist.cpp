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
	ll j;
	for(j=1;j<=t;j++)
	{
		ll n,k,v;
		vector<string> s;
		ll i;
		cin>>n>>k>>v;
		for(i=0;i<n;i++)
		{
			string ss;
			cin>>ss;
			s.pb(ss);
		}
		ll x=(((v-1)*k)+1)%n;
		ll att=0;
		cout<<"Case #"<<j<<": ";
		vector<pair<ll,string> > ans;
		for(i=(x-1+n)%n;i<n;i++)
		{
			if(att==k)
				break;
			ans.pb(mp(i,s[i]));
			att++;
		}
		for(i=0;i<n;i++)
		{
			if(att==k)
				break;
			ans.pb(mp(i,s[i]));
			att++;
		}
		sort(ans.begin(),ans.end());
		for(i=0;i<sz(ans);i++)
			cout<<ans[i].second<<" ";
		cout<<"\n";
	}
	return 0;
}