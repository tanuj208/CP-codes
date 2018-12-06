#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
map<pii,pii> x;
ll maximumRad=0;
ll stones=1;
pii indexes=mp(-1,-1);

void find(ll a,ll b,ll c,ll i)
{
	pii m=mp(a,b);
	pii altm=mp(b,a);
	if(x.find(altm)!=x.end())
		m=altm;
	if(x.find(m)!=x.end())
	{
		ll third=c+x[m].first;
		ll ind=x[m].second;
		if(c>x[m].first)
		{
			x[m].first=c;
			x[m].second=i;
		}
		ll r=min(third,min(a,b));
		if(r>maximumRad)
		{
			maximumRad=r;
			stones=2;
			indexes=mp(ind,i);
		}
	}
	else
		x.insert(mp(mp(a,b),mp(c,i)));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	//two keys are the sides and two values are third side and stone number
	cin>>n;
	ll i;
	for(i=0;i<n;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		find(a,b,c,i);
		find(b,c,a,i);
		find(a,c,b,i);
		ll r=min(a,min(b,c));
		if(r>=maximumRad)
		{
			maximumRad=r;
			stones=1;
			indexes=mp(i,-1);
		}
	}
	cout<<stones<<endl;
	if(stones==1)
		cout<<indexes.first+1<<endl;
	else
		cout<<indexes.first+1<<" "<<indexes.second+1<<endl;
	return 0;
}