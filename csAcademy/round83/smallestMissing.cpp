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
	ll i,val;
	vector<ll> a;
	ll ans=(m*(m+1))/2;
	ll last=m+1;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	for(i=0;i<n;i++)
	{
		if(a[i]<last)
		{
			ans-=a[i];
			ans+=last;
			last++;
		}
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}