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
	ll w,t;
	cin>>t;
	ll i;
	vector<ll> pp;
	pp.pb(1);
	for(i=1;i<=104;i++)
		pp.pb(pp[i-1]*2)
	for(w=1;w<=t;w++)
	{
		ll n,m,p;
		cin>>n>>m>>p;
		vector<string> x;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			x.pb(s);
		}
	}
	return 0;
}