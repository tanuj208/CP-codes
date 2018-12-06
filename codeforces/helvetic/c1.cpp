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
	ll n,p;
	cin>>n>>p;
	ll x[100005];
	ll i;
	ll totalSum=0;
	for(i=0;i<n;i++)
	{
		cin>>x[i];
		x[i]=x[i]%p;
		totalSum+=x[i];
	}
	ll sum=0;
	ll ans=0;
	ll restSum;
	for(i=0;i<n-1;i++)
	{
		sum+=x[i];
		restSum=totalSum-sum;
		ans=max(sum%p+restSum%p,ans);
	}
	cout<<ans<<endl;
	return 0;
}