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
	ll n,i;
	cin>>n;
	ll x=sqrt(n);
	ll x1=ceil(sqrt(n));
	if(n-x*x>x1*x1-n)
		x=x1;
	ll val=x;
	ll lt=1;
	ll cnt=0;
	while(cnt!=n)
	{
		for(i=val;i>=lt;i--)
		{
			if(i>n)
				continue;
			cout<<i<<" ";
			cnt++;
			if(cnt==n)
				break;
		}
		val+=x;
		lt+=x;
	}
	cout<<endl;
	return 0;
}