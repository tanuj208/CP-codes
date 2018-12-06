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
	ll n,h;
	cin>>n>>h;
	if(h<1500000000)
	{
		ll xx=(h*(h+1))/2;
		if(xx<n)
		{
			ll l=1;
			ll r=1500000000;
			ll val=((h)*(h-1))/2;
			ll mid;
			while(l!=r)
			{
				mid=(l+r)/2;
				ll x=(mid)*(mid)-val;
				if(x<n)
				{
					l=mid+1;
					continue;
				}
				else if(x>n)
				{
					r=mid;
					continue;
				}
				else
					break;
			}
			if(l!=r)
				l=mid;
			ll x=(l)*(l)-val;
			while(x<n)
			{
				l++;
				x=(l)*(l)-val;
			}
			while(x>=n)
			{
				l--;
				x=(l)*(l)-val;
			}
			// cout<<l<<endl;
			ll ans=2*l-h;
			if(n-x>l)
				ans+=2;
			else
				ans++;
			cout<<ans<<endl;
			return 0;
		}
	}
	ll l=1;
	ll r=1500000000;
	while(l!=r)
	{
		ll mid=(l+r)/2;
		ll x=(mid*(mid+1))/2;
		if(x<n)
		{
			l=mid+1;
			continue;
		}
		else if(x>n)
		{
			r=mid;
			continue;
		}
		else
		{
			cout<<mid<<endl;
			return 0;
		}
	}
	ll x=(l*(l+1))/2;
	while(x<n)
	{
		l++;
		x=(l*(l+1))/2;
	}
	cout<<l<<endl;
	return 0;
}