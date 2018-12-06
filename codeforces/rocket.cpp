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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll m,n;
	cin>>m>>n;
	vector<ll> seq;
	ll i;
	ll x;
	for(i=0;i<n;i++)
	{
		cout<<"1\n";
		fflush(stdout);
		cin>>x;
		if(x==0)
			return 0;
		if(x==-1)
			seq.pb(0);
		else
			seq.pb(1);
	}
	ll l=1;
	ll r=m;
	ll mid=(l+r)/2;
	ll pos=0;
	while(true)
	{
		mid=(l+r)/2;
		cout<<mid<<endl;
		fflush(stdout);
		cin>>x;
		if(x==0)
			return 0;
		ll val=seq[pos];
		pos=(pos+1)%n;
		if((x==1 && val==1) || (x==-1 && val==0))
			l=mid+1;
		else if((x==-1 && val==1) || (x==1 && val==0))
			r=mid-1;
	}
	return 0;
}