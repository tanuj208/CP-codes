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
	ll a[1005];
	ll i;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(n%2!=0)
		cout<<a[n/2]<<endl;
	else
		cout<<a[(n-1)/2]<<endl;
	return 0;
}