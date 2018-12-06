#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,mm;
vector<ll> a,b;

bool valid(ll x)
{
	ll i;
	ll lt=mm;
	for(i=0;i<n;i++)
	{
		ll tmp=max((ll)0,a[i]-(x/b[i]));
		if(tmp>lt)
			return false;
		lt-=tmp;
	}
	if(lt<0)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>mm;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		b.pb(val);
	}
	ll l=0;
	ll r=LLONG_MAX;
	ll m=(l+r)/2;
	while(l<r)
	{
		m=(l+r)/2;
		if(valid(m))
			r=m-1;
		else
			l=m+1;
	}
	while(valid(m) && m>0)
		m--;
	while(!valid(m) && m<LLONG_MAX)
		m++;
	cout<<m<<endl;
	return 0;
}