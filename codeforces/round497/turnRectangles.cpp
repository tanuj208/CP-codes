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
	ll ans=1;
	ll i;
	ll last=LLONG_MAX;
	for(i=0;i<n;i++)
	{
		ll w,h;
		cin>>w>>h;
		if(max(w,h)<=last)
			last=max(w,h);
		else if(min(w,h)<=last)
			last=min(w,h);
		else ans=0;
	}
	if(ans==0)
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}