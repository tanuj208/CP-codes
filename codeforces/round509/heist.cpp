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
	ll i,val;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	ll r=a[n-1]-a[0]+1;
	cout<<r-n<<endl;
	return 0;
}