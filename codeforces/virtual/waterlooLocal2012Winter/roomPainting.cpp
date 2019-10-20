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
	multiset<double> x;
	ll i;
	for(i=0;i<n;i++)
	{
		double a;
		cin>>a;
		x.insert(a);
	}
	double ans=0;
	for(i=0;i<m;i++)
	{
		double val;
		cin>>val;
		auto it=x.lower_bound(val);
		ans+=(*it)-val;
	}
	cout<<ans<<endl;
	// printf("%.6lf\n",ans);
	return 0;
}