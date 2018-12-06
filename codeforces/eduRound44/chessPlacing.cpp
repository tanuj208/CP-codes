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
	vector<ll> a;
	ll i,val;
	for(i=0;i<n/2;i++)
	{
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	ll x=0,y=0;
	for(i=0;i<n/2;i++)
		x=x+abs(a[i]-2*i-1);
	for(i=0;i<n/2;i++)
		y=y+abs(a[i]-2*i-2);
	cout<<min(x,y)<<endl;
	return 0;
}