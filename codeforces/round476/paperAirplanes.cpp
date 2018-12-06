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
	ll k,n,s,p;
	cin>>k>>n>>s>>p;
	ll x;
	x=ceil(double(k*ceil(double(n)/double(s)))/double(p));
	cout<<x<<endl;
	return 0;
}