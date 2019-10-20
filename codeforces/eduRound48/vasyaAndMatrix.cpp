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
	ll n,m;
	cin>>n>>m;
	ll i,j,val;
	vector<ll> a,b;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<m;i++)
	{
		cin>>val;
		b.pb(val);
	}
	ll ans[104][104];
	for(i=0;i<n-1;i++)
	{
		ans[i][0]=a[i];
		for(j=1;j<m;j++)
			ans[i][j]=0;
	}
	for(i=0;i<m;i++)
	{
		ll xorr=0;
		for(j=0;j<n-1;j++)
			xorr=xorr^ans[j][i];
		ans[n-1][i]=xorr^b[i];
	}
	ll xorr=0;
	for(i=0;i<m;i++)
		xorr^=ans[n-1][i];
	if(xorr!=a[n-1])
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}