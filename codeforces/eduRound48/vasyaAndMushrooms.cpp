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
	vector<ll> a[2];
	ll tmp1[2][n+5],tmp2[2][n+5];
	vector<ll> cum1(300005,0),cum2(300005,0);
	vector<ll> cum(300005,0);
	ll i,val,j;
	ll mush=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>val;
			a[i].pb(val);
		}
	}
	ll s=0;
	for(j=n-1;j>=0;j--)
	{
		s+=a[0][j]+a[1][j];
		cum[j]=s;
	}
	ll t=0;
	for(i=0;i<n;i++)
		tmp1[0][i]=t*a[0][i],t++;
	for(i=n-1;i>=0;i--)
		tmp1[1][i]=t*a[1][i],t++;
	t=1;
	s=0;
	for(i=n-1;i>=0;i--)
	{
		s+=tmp1[0][i]+tmp1[1][i];
		cum1[i]=s;
	}
	tmp2[0][0]=0;
	for(i=0;i<n;i++)
		tmp2[1][i]=t*a[1][i],t++;
	for(i=n-1;i>0;i--)
		tmp2[0][i]=t*a[0][i],t++;
	s=0;
	for(i=n-1;i>=0;i--)
	{
		s+=tmp2[0][i]+tmp2[1][i];
		cum2[i]=s;
	}
	ll ans=max(cum1[0],cum2[0]);
	if(n==1)
	{
		cout<<ans<<endl;
		return 0;
	}
	t=2;
	mush=a[1][0];
	for(i=1;i<n;i++)
	{
		if(i%2==1)
		{
			mush+=t*a[1][i];
			t++;
			mush+=t*a[0][i];
			t++;
			ans=max(ans,mush+cum1[i+1]+(i+1)*cum[i+1]);
		}
		else
		{
			mush+=t*a[0][i];
			t++;
			mush+=t*a[1][i];
			t++;
			ans=max(ans,mush+cum2[i+1]+i*cum[i+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}