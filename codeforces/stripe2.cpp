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
	vector<ll> s;
	ll i,val;
	ll sum=0;
	map<ll,ll> cnt;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		sum+=val;
		cnt[sum]++;
		s.pb(sum);
	}
	if(sum%3!=0)
	{
		cout<<"0\n";
		return 0;
	}
	ll x=sum/3;
	ll ans=0;
	sum=0;
	for(i=n-1;i>1;i--)
	{
		cnt[s[i]]--;
		sum+=a[i];
		if(sum==x)
		{
			ll xx=cnt[x];
			if(s[i-1]==x && xx!=0)
				xx--;
			ans+=xx;
		}
	}
	cout<<ans<<endl;
	return 0;
}