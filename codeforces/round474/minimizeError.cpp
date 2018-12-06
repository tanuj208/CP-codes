#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

ll diff[1005];
ll n,k1,k2;

ll maximum()
{
	ll i;
	ll ans=-1;
	ll j;
	for(i=0;i<n;i++)
	{
		if(ans<diff[i])
		{
			ans=diff[i];
			j=i;
		}
	}
	return j;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k1>>k2;
	ll k=k1+k2;
	ll a[1005];
	ll b[1005];
	ll i;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++)
		diff[i]=abs(a[i]-b[i]);
	for(i=0;i<k;i++)
	{
		ll j=maximum();
		diff[j]--;
		if(diff[j]<0)
			diff[j]=-diff[j];
	}
	ll ans=0;
	for(i=0;i<n;i++)
		ans+=(diff[i]*diff[i]);
	cout<<ans<<endl;
	return 0;
}