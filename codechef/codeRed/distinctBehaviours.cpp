#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

ll ways(ll n)
{
	return ((n)*(n-1))/2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<ll>a;
	lp(i,0,n)
	{
		ll b;
		cin>>b;
		a.pb(b);
	}
	sort(a.begin(),a.end());
	ll c=1;
	ll ans=0;
	lp(i,0,n-1)
	{
		if(a[i]==a[i+1])
			c++;
		else
		{
			ans+=ways(c);
			c=1;
		}
		// cout<<c<<endl;
	}
	ans+=ways(c);
	cout<<ans<<endl;
	return 0;
}
		