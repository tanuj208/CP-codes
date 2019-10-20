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
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll x=a+b;
		ll y=a-b;
		if(y!=1)
		{
			cout<<"NO\n";
			continue;
		}
		ll i;
		ll flag=0;
		for(i=2;i<=sqrt(x);i++)
			if(x%i==0)
				flag=1;
		if(flag==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}