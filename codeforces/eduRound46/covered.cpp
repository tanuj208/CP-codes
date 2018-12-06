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
	vector<pii> x;
	ll i;
	for(i=0;i<n;i++)
	{
		ll l,r;
		cin>>l>>r;
		x.pb(mp(l,r));
	}
	sort(x.begin(),x.end());
	vector<ll> ans(200005,0);
	ll cnter=1;
	multiset<ll> tmp;
	tmp.insert(x[0].second);
	for(i=1;i<n;i++)
	{
		ll xx=x[i-1].first;
		auto it=tmp.begin();
		for(it=tmp.begin();it!=tmp.end();it++)
		{
			if((*it)>=x[i].first)
				break;
			ans[cnter]+=((*it)-xx+1);
			xx=(*it)+1;
			cnter--;
		}
		tmp.erase(tmp.begin(),it);
		ans[cnter]+=x[i].first-xx;
		tmp.insert(x[i].second);
		cnter++;
	}
	auto it=tmp.begin();
	ll xx=x[n-1].first;
	for(it=tmp.begin();it!=tmp.end();it++)
	{
		ans[cnter]+=((*it)-xx+1);
		xx=(*it)+1;
		cnter--;
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}