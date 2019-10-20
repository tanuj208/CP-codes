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
	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}
	if(n==2)
	{
		cout<<"2\n";
		return 0;
	}
	ll ans=0;
	ll p=1;
	while(n!=0)
	{
		if(n<=p)
		{
			ans++;
			break;
		}
		n-=p;
		p*=2;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}