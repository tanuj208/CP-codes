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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,a,b;
		cin>>n>>a>>b;
		vector<ll> hashh(10006,0);
		ll i,val;
		for(i=0;i<n;i++)
		{
			cin>>val;
			hashh[val]++;
		}
		ll aa=hashh[a]*hashh[b];
		double ans=(double)aa/(double)(n*n);
		printf("%.10lf\n",ans);
	}
	return 0;
}