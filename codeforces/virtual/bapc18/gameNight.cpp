#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	string s;
	ll i;
	cin>>s;
	vector<ll> cuma,cumb,cumc;
	cuma.pb(0);
	cumb.pb(0);
	cumc.pb(0);
	ll A=0,B=0,C=0;
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='A')
		{
			A++;
			cuma.pb(cuma[i]+1);
			cumb.pb(cumb[i]);
			cumc.pb(cumc[i]);
		}
		if(s[i]=='B')
		{
			B++;
			cumb.pb(cumb[i]+1);
			cuma.pb(cuma[i]);
			cumc.pb(cumc[i]);
		}
		if(s[i]=='C')
		{
			C++;
			cumc.pb(cumc[i]+1);
			cumb.pb(cumb[i]);
			cuma.pb(cuma[i]);
		}
	}
	ll ans=LLONG_MAX;
	for(i=1;i<=n;i++)
	{
		ll cnt=n;
		ll x=i;
		ll y=x+A-1;
		if(y>n)
			y%=n;
		if(y<x)
		{
			cnt-=cuma[y];
			cnt-=(cuma[n]-cuma[x-1]);
		}
		else
			cnt-=(cuma[y]-cuma[x-1]);
		x=y+1;
		y=x+B-1;
		if(y>n)
			y%=n;
		if(y<x)
		{
			cnt-=cumb[y];
			cnt-=(cumb[n]-cumb[x-1]);
		}
		else
			cnt-=(cumb[y]-cumb[x-1]);
		x=y+1;
		y=x+C-1;
		if(y>n)
			y%=n;
		if(y<x)
		{
			cnt-=cumc[y];
			cnt-=(cumc[n]-cumc[x-1]);
		}
		else
			cnt-=(cumc[y]-cumc[x-1]);
		ans=min(ans,cnt);
	}
	
	for(i=1;i<=n;i++)
	{
		ll cnt=n;
		ll x=i;
		ll y=x+A-1;
		if(y>n)
			y%=n;
		if(y<x)
		{
			cnt-=cuma[y];
			cnt-=(cuma[n]-cuma[x-1]);
		}
		else
			cnt-=(cuma[y]-cuma[x-1]);
		x=y+1;
		y=x+C-1;
		if(y>n)
			y%=n;
		if(y<x)
		{
			cnt-=cumc[y];
			cnt-=(cumc[n]-cumc[x-1]);
		}
		else
			cnt-=(cumc[y]-cumc[x-1]);
		x=y+1;
		y=x+B-1;
		if(y>n)
			y%=n;
		if(y<x)
		{
			cnt-=cumb[y];
			cnt-=(cumb[n]-cumb[x-1]);
		}
		else
			cnt-=(cumb[y]-cumb[x-1]);
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}