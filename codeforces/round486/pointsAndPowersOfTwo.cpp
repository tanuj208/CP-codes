#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> powers;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	vector<ll> a;
	ll i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	ll ans=1;
	pair<pii,ll> x;
	sort(a.begin(),a.end());
	powers.pb(1);
	for(i=1;i<=40;i++)
		powers.pb(powers[i-1]*2);
	for(i=0;i<n-1;i++)
	{
		for(ll j=0;j<=40;j++)
		{
			ll xx=a[i]+powers[j];
			if(binary_search(a.begin(),a.end(),xx)==true)
			{
				ans=2;
				x.first.first=a[i];
				x.first.second=xx;
				if(binary_search(a.begin(),a.end(),xx+powers[j])==true)
				{
					ans=3;
					x.first.first=a[i];
					x.first.second=xx;
					x.second=xx+powers[j];
					break;
				}
			}
		}
		if(ans==3)
			break;
	}
	cout<<ans<<endl;
	if(ans==1)
		cout<<a[0]<<endl;
	else if(ans==2)
		cout<<x.first.first<<" "<<x.first.second<<endl;
	else if(ans==3)
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
	return 0;
}