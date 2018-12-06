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
	ll k;
	cin>>k;
	ll i;
	pair<pii,pii> ans;
	ans.first.first=-1;
	map<ll,pii> x;
	for(i=0;i<k;i++)
	{
		ll n;
		cin>>n;
		vector<ll> a;
		ll j;
		ll sum=0;
		for(j=0;j<n;j++)
		{
			ll val;
			cin>>val;
			a.pb(val);
			sum+=val;
		}
		for(j=0;j<n;j++)
		{
			if(x.find(sum-a[j])==x.end())
				x.insert(mp(sum-a[j],mp(i+1,j+1)));
			else
			{
				if(x[sum-a[j]].first==i+1)
					continue;
				ans.first.first=x[sum-a[j]].first;
				ans.first.second=x[sum-a[j]].second;
				ans.second.first=i+1;
				ans.second.second=j+1;
			}
		}
	}
	if(ans.first.first==-1)
		cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		cout<<ans.first.first<<" "<<ans.first.second<<endl;
		cout<<ans.second.first<<" "<<ans.second.second<<endl;
	}
	return 0;
}