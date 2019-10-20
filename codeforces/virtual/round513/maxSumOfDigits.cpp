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
	ll tmp=n;
	ll digits=0;
	ll ans=0;
	ll hig;
	while(tmp!=0)
	{
		hig=tmp%10;
		tmp/=10;
		digits++;
	}
	ll num=0;
	ll p=1;
	while(digits!=1)
	{
		num+=9*p;
		p*=10;
		digits--;
		ans+=9;
	}
	num+=p*(hig-1);
	ans+=(hig-1);
	ll rem=n-num;
	while(rem!=0)
	{
		ans+=rem%10;
		rem/=10;
	}
	cout<<ans<<endl;
	return 0;
}