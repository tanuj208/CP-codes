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
	vector<ll> p;
	ll i,val;
	ll ind;
	for(i=0;i<n;i++)
	{
		cin>>val;
		if(val==m)
			ind=i;
		p.pb(val);
	}
	map<ll,ll> x;
	ll l=0;
	// x[1]-> 1 left m zyada
	for(i=ind-1;i>=0;i--)
	{
		if(p[i]<m)
			l++;
		else
			l--;
		x[l]++;
	}
	map<ll,ll> xx;
	l=0;
	for(i=ind+1;i<n;i++)
	{
		if(p[i]<m)
			l++;
		else
			l--;
		xx[l]++;
	}
	x[0]++;
	xx[0]++;
	ll ans=0;
	for(auto it=x.begin();it!=x.end();it++)
	{
		ll a=it->first;
		ll b=it->second;
		if(xx.find(-a)!=xx.end())
			ans+=b*xx[-a];
		if(xx.find(-a-1)!=xx.end())
			ans+=b*xx[-a-1];
	}
	cout<<ans<<endl;
	return 0;
}