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
	ll a,b,c,n;
	cin>>a>>b>>c>>n;
	ll x=n-(a+b-c);
	ll flag=0;
	if(c>a || c>b)
		flag=1;
	if(x<1)
		flag=1;
	if(flag==1)
		cout<<"-1\n";
	else
		cout<<x<<endl;
	return 0;
}