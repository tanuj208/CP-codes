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
	ll n,m;
	cin>>n>>m;
	ll mval=(n*(n-1))/2;
	ll lval;
	if(n%2==1)
	{
		ll x=n/2;
		lval=x*(x+1);
	}
	else
	{
		ll x=n/2;
		lval=(x*(x+1))/2+(x*(x-1))/2;
	}
	ll sum=0;
	while(m--)
	{
		ll x,d;
		cin>>x>>d;
		if(d>0)
			sum+=(n*x+mval*d);
		else
			sum+=(n*x+lval*d);
	}
	double ans=(double)sum/(double)n;
	printf("%.10f\n",ans);
	return 0;
}