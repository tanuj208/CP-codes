#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll ncr[5004][5004];

ll powerr(ll a,ll b,ll modd)
{
	ll val=1;
	ll power=b;
	while(power!=0)
	{
		if(power%2==1)
			val=(val*a)%modd;
		a=a*a;
		a=a%modd;
		power=power/2;
	}
	return val;
}

void calculate(ll i,ll j)
{
	if(ncr[i][j]!=-1)
		return;
	if(i<j)
	{
		ncr[i][j]=0;
		return;
	}
	calculate(i-1,j-1);
	calculate(i-1,j);
	ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%(mod-1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,j;
	ll t;
	cin>>t;
	for(i=1;i<=5000;i++)
		for(j=1;j<=5000;j++)
			ncr[i][j]=-1;
	for(i=0;i<=5000;i++)
		ncr[i][0]=1,ncr[i][i]=1;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll> a;
		vector<ll> arr(5005,0);
		ll val;
		for(i=0;i<n;i++)
		{
			cin>>val;
			a.pb(val);
		}
		sort(a.begin(),a.end());
		calculate(n-1,k-1);
		for(i=1;i<n-1;i++)
		{
			calculate(i,k-1);
			calculate(n-i-1,k-1);
			arr[i]=(ncr[n-1][k-1]-ncr[i][k-1]-ncr[n-i-1][k-1]+2*mod-2)%(mod-1);
		}
		ll ans=1;
		for(i=1;i<n-1;i++)
			if(arr[i]!=0)
				ans=(ans*powerr(a[i],arr[i],mod))%mod;
		cout<<ans<<"\n";
	}
	return 0;
}