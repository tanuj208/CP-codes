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
	ll w;
	for(w=1;w<=t;w++)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll> a;
		ll i,val;
		for(i=0;i<n;i++)
		{
			cin>>val;
			a.pb(val);
		}
		sort(a.begin(),a.end());
		i=0;
		ll ans=0;
		ll cnt=0;
		while(i<n)
		{
			a[i]-=cnt;
			while(a[i]<=0 && i<n)
			{
				i++;
				a[i]-=cnt;
			}
			if(i>=n)
				break;
			ans+=min(k,n-i);
			i+=k;
			cnt++;
		}
		cout<<"Case #"<<w<<": "<<ans<<"\n";
	}
	return 0;
}