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
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	if(n%m==0)
	{
		cout<<"0\n";
		return 0;
	}
	ll x=n/m;
	ll a1=(n-(m*x))*b;
	ll a2=(m*(x+1)-n)*a;
	cout<<min(a1,a2)<<endl;
	return 0;
}