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
	ll i,val;
	map<ll,vector<ll> > x;
	map<ll,ll> ans;
	for(i=0;i<n;i++)
	{
		cin>>val;
		x[val].pb(i);
	}
	while(!x.empty())
	{
		auto it=x.begin();
		ll a=it->first;
		vector<ll> tmp=it->second;
		sort(tmp.begin(),tmp.end());
		for(i=0;i<sz(tmp)-1;i+=2)
			x[2*a].pb(tmp[i+1]);
		if(sz(tmp)%2==1)
			ans[tmp[sz(tmp)-1]]=a;
		x.erase(it);
	}
	cout<<sz(ans)<<endl;
	for(auto it=ans.begin();it!=ans.end();it++)
		cout<<it->second<<" ";
	cout<<endl;
	return 0;
}