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
		ll n,k;
		cin>>n>>k;
		vector<ll> m,t;
		ll msum=0,tsum=0;
		ll i;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			if(i%2==0)
			{
				m.pb(val);
				msum+=val;
			}
			else
			{
				t.pb(val);
				tsum+=val;
			}
		}
		sort(m.begin(),m.end());
		sort(t.begin(),t.end());
		if(tsum>msum)
		{
			cout<<"YES\n";
			continue;
		}
		ll flag=0;
		ll len=sz(m);
		for(i=0;i<k;i++)
		{
			if(i>=sz(t) || len-1-i<0)
				break;
			if(t[i]>=m[len-i-1])
				break;
			tsum-=t[i];
			msum+=t[i];
			tsum+=m[len-1-i];
			msum-=m[len-1-i];
			if(tsum>msum)
			{
				cout<<"YES\n";
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		cout<<"NO\n";
	}
	return 0;
}