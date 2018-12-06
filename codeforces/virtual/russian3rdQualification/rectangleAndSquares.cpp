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
		ll a,b,c;
		cin>>a>>b>>c;
		ll rect = a*b;
		ll number = rect/(c*c);
		ll ans;
		ll diff = LLONG_MAX;
		if(number!=0)
		{
			ans = c*c*number;
			diff = abs(ans-rect);
		}
		ans = c*c*(number+1);
		if(abs(ans-rect)<=diff)
		{
			cout<<c*c*(number+1)<<endl;
		}
		else
			cout<<c*c*number<<endl;
	}
	return 0;
}