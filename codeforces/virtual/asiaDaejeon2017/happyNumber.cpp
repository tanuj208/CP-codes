#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll value(ll x)
{
	ll ans=0;
	while(x!=0)
	{
		ll t=x%10;
		ans+=(t*t);
		x/=10;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	set<ll> x;
	while(n!=1)
	{
		if(x.find(n)==x.end())
			x.insert(n);
		else
		{
			cout<<"UNHAPPY\n";
			exit(0);
		}
		n=value(n);
	}
	cout<<"HAPPY\n";
	return 0;
}