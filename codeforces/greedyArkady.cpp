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
	ll n,k,m,d;
	cin>>n>>k>>m>>d;
	ll i;
	ll ans=0;
	for(i=1;i<=d;i++)
	{
		if(1e18/k<i-1)
			continue;
		ll cand=n/((i-1)*k+1);
		if(cand>m)
			cand=m;
		if(cand<1)
			cand=1;
		if(1e18/k<cand || 1e18/(k*cand)<i-1)
		{
			if(i==1)
				ans=max(ans,i*cand);
			continue;
		}
		ll sss=cand*k*(i-1);
		ll ss=cand*k*i;
		if(n<sss+cand || n>=ss+cand)
			continue;
		ans=max(ans,i*cand);
	}
	cout<<ans<<endl;
	return 0;
}