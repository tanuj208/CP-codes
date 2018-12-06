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
	ll a,b;
	cin>>a>>b;
	vector<ll> diva,divb;
	ll i;
	for(i=1;i<=sqrt(a);i++)
		if(a%i==0)
			diva.pb(i);
	for(i=1;i<=sqrt(b);i++)
		if(b%i==0)
			divb.pb(i);
	ll ans = 2*(1+a+b);
	for(i=1;i<=sqrt(a+b);i++)
	{
		if((a+b)%i!=0)
			continue;
		ll x=i;
		ll y=(a+b)/i;
		ll ind=lower_bound(diva.begin(),diva.end(),x) - diva.begin();
		if(ind!=0 || (ind==0 && diva[ind]<=x))
		{
			if(ind==sz(diva) || diva[ind]>x)
				ind--;
			ll y1 = a/diva[ind];
			if(y1<=y && diva[ind]<=x)
				ans=min(ans,2*(x+y));
		}
		ind=lower_bound(divb.begin(),divb.end(),x) - divb.begin();
		if(ind!=0 || (ind==0 && divb[ind]<=x))
		{
			if(ind==sz(divb) || divb[ind]> x)
				ind--;
			ll y1 = b/divb[ind];
			if(y1<=y && divb[ind]<=x)
				ans=min(ans,2*(x+y));
		}
	}
	cout<<ans<<endl;
	return 0;
}