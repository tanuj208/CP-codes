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
	vector<double> a;
	ll i;
	double val;
	ll ans=0;
	ll numberOfIntegers=0;
	for(i=0;i<(2*n);i++)
	{
		cin>>val;
		a.pb(val);
		if(val-floor(val)==0)
			numberOfIntegers++;
		else
			ans+=val-floor(val);
	}
	return 0;
}