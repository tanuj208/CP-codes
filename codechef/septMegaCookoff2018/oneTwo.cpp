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
		set<ll> ans;
		vector<ll> ne;
		ll n;
		cin>>n;
		ll i,val;
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			cin>>val;
			a.pb(val);
		}
		ne.pb(a[0]);
		ans.insert(a[0]);
		for(i=1;i<n;i++)
		{
			ll j;
			vector<ll> nee;
			if(ans.find(a[i])==ans.end())
			{
				ans.insert(a[i]);
				nee.pb(a[i]);
			}
			for(j=0;j<sz(ne);j++)
			{
				if(ans.find(ne[j]+a[i])==ans.end())
				{
					ans.insert(ne[j]+a[i]);
					nee.pb(ne[j]+a[i]);
				}
			}
			ne=nee;
		}
		cout<<sz(ans)<<endl;
	}
	return 0;
}