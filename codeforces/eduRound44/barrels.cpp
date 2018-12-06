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
	ll n,k,l;
	cin>>n>>k>>l;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n*k;i++)
	{
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	ll len=upper_bound(a.begin(),a.end(),a[0]+l)-a.begin();
	if(len<n)
	{
		cout<<"0\n";
		return 0;
	}
	ll ans=a[0];
	ll x=1;
	ll c=1;
	ll lelia[100005]={0};
	lelia[0]=1;
	for(i=1;i<len;i++)
	{
		if(x==n)
			break;
		if(c==k)
		{
			c=0;
			ans+=a[i];
			lelia[i]=1;
			x++;
		}
		c++;
	}
	for(i=len-1;i>=0;i--)
	{
		if(x==n)
			break;
		if(lelia[i]==0)
		{
			ans+=a[i];
			lelia[i]=1;
			x++;
		}
	}
	cout<<ans<<endl;
	return 0;
}