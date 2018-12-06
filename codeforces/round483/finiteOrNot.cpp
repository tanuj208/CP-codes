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
	while(n--)
	{
		ll p,q,b;
		cin>>p>>q>>b;
		if(p==0)
		{
			cout<<"Finite\n";
			continue;
		}
		ll x=__gcd(p,q);
		q=q/x;
		ll flag=1;
		while(q>1)
		{
			if(b%q==0)
				break;
			ll m=__gcd(q,b);
			if(m==1)
			{
				flag=0;
				break;
			}
			while(q%m==0)
				q=q/m;
			if(b%q==0)
				break;
		}
		if(flag==1)
			cout<<"Finite\n";
		else
			cout<<"Infinite\n";
	}
	return 0;
}