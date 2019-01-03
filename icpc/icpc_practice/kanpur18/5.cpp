#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define endl "\n"


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
	ll t;
	cin >>t;
	while(t--)
	{
		ll x,y,s,u,v;
		cin >> x >> y >> s >> u >> v;
		ll c=0;
		ll z=x;
		ll f=0;
		while(z<=s)
		{
			if(z==s)f=1;
			z*=2;
		}
		z=y;
		while(z<=s)
		{
			if(z==s)f=2;
			z*=2;
		}
		if(f==1)
		{
			s/=x;
		}
		if(f==2)
		{
			s/=y;
			u=v-u;
		}
		v%=mod;
		s%=mod;
		cout<<((((s*power(u%mod,mod-2))%mod)*v)%mod)<<endl;


	}
	return 0;
}