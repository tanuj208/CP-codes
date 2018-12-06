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
	ll i,val;
	vector<ll> a;
	vector<ll> lit(100005,0);
	vector<ll> off(100005,0);
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	ll x=a[1];
	lit[0]=a[0];
	off[1]=a[1]-a[0];
	ll totallit=0;
	ll totaloff=0;
	for(i=2;i<n;i++)
	{
		if(i%2==0)
			lit[i]=lit[i-2]+a[i]-x;
		else
			off[i]=off[i-2]+a[i]-x;
		x=a[i];
	}
	if(n%2==0)
	{
		lit[n]=lit[n-2]+m-a[n-1];
		totallit=lit[n];
		totaloff=off[n-1];
	}
	else
	{
		off[n]=off[n-2]+m-a[n-1];
		totaloff=off[n];
		totallit=lit[n-1];
	}
	ll ans=totallit;
	x=0;
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			if(a[i]-1==x && a[i+1]==a[i]+1)
			{
				x=a[i];
				continue;
			}
		}
		else
		{
			if(a[i]-1==x && a[i]+1==m)
			{
				x=a[i];
				continue;
			}
		}
		if(i%2==0)
		{
			ll tmp;
			if(i==0)
				tmp=lit[i]-1+totaloff;
			else
				tmp=lit[i]-1+totaloff-off[i-1];
			ans=max(ans,tmp);
		}
		else
		{
			ll x=a[i]+1;
			ll tmp=lit[i-1]+1+totaloff-off[i];
			ans=max(ans,tmp);
		}
		x=a[i];
	}
	cout<<ans<<endl;
	return 0;
}