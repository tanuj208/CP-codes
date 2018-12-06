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
	ll n,s;
	cin>>n>>s;
	ll i,val;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	ll ans=0;
	i=n/2;
	if(a[i]==s)
	{
		cout<<ans<<endl;
		return 0;
	}
	if(a[i]<s)
	{
		while(a[i]<s && i<n)
		{
			ans+=s-a[i];
			i++;
		}
	}
	else
	{
		while(a[i]>s && i>=0)
		{
			ans+=a[i]-s;
			i--;
		}
	}
	cout<<ans<<endl;
	return 0;
}