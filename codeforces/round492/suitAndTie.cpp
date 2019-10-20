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
	vector<ll> a(204);
	ll i,val,j;
	for(i=0;i<2*n;i++)
	{
		cin>>val;
		a[i+1]=val;
	}
	ll ans=0;
	for(i=1;i<=2*n;i+=2)
	{
		ll x=a[i];
		for(j=i+1;j<=2*n;j++)
			if(a[j]==x)
				break;
		ans+=j-i-1;
		for(;j>i;j--)
			a[j]=a[j-1];
	}
	cout<<ans<<endl;
	return 0;
}