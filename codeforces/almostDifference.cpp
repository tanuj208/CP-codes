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
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	map<ll,ll> cnt;
	cnt[a[0]]++;
	ll cursum=a[0];
	unsigned long long ans=0;
	bool negative=false;
	for(i=1;i<n;i++)
	{
		if(!negative)
		{
			ans+=i*a[i];
			if(ans<cursum)
			{
				ans=cursum-ans;
				negative=true;
			}
			else
				ans-=cursum;
		}
		else
		{
			ans+=cursum;
			if(ans<=i*a[i])
			{
				ans=i*a[i]-ans;
				negative=false;
			}
			else
				ans-=i*a[i];
		}
		cursum+=a[i];
		if(!negative)
		{
			ans+=cnt[a[i]+1];
			if(ans<cnt[a[i]-1])
			{
				ans=cnt[a[i]-1]-ans;
				negative=true;
			}
			else
				ans-=cnt[a[i]-1];
		}
		else
		{
			ans+=cnt[a[i]-1];
			if(ans<=cnt[a[i]+1])
			{
				ans=cnt[a[i]+1]-ans;
				negative=false;
			}
			else
				ans-=cnt[a[i]+1];
		}
		cnt[a[i]]++;
	}
	if(!negative)
		cout<<ans<<endl;
	else
		cout<<"-"<<ans<<endl;
	return 0;
}