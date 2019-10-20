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
	ll n,d;
	cin>>n>>d;
	ll i;
	vector<ll> x;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		x.pb(val);
	}
	multiset<ll> p;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		p.insert(val);
	}
	auto it=p.end();
	it--;
	// sort(p.begin(),p.end());
	ll score = x[d-1]+*it;
	p.erase(it);
	for(i=d;i<n;i++)
	{
		it = p.end();
		it--;
		p.erase(it);
	}
	ll imp=0;
	for(i=d-2;i>=0;i--)
	{
		if(x[i] > score)
			break;
		it=p.upper_bound(score-x[i]);
		if(it==p.begin())
			break;
		it--;
		p.erase(it);
		imp++;
	}
	ll ans=d-imp;
	cout<<ans<<endl;
	return 0;
}