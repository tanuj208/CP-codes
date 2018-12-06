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
	ll n,m,k;
	cin>>n>>m>>k;
	if(k<=n-1)
	{
		cout<<k+1<<" "<<1<<endl;
		return 0;
	}
	k-=(n-1);
	if(k<=m-1)
	{
		cout<<n<<" "<<k+1<<endl;
		return 0;
	}
	k-=(m-1);
	if(k<=m-1)
	{
		cout<<n-1<<" "<<m-k+1<<endl;
		return 0;
	}
	k-=(m-1);
	ll x=(k-1)/(m-1);
	if(x%2==0)
	{
		k=k%(m-1);
		if(k==0)
			k=m-1;
		cout<<n-x-2<<" "<<k+1<<endl;
		return 0;
	}
	else
	{
		k=(k)%(m-1);
		if(k==0)
			k=m-1;
		cout<<n-x-2<<" "<<m-k+1<<endl;
		return 0;
	}
	return 0;
}