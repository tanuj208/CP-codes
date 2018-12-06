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
	vector<pii> xx;
	ll i;
	for(i=0;i<n;i++)
	{
		ll l,r;
		cin>>l>>r;
		xx.pb(mp(l,r));
	}
	multiset<pii> x;
	for(i=0;i<n;i++)
		x.insert(xx[i]);	
	ll ans=0;
	while(!x.empty())
	{
		ans++;
		auto it=x.begin();
		pii tmp=*it;
		x.erase(it);
		ll save = tmp.first;
		while(true)
		{
			if(x.empty())
			{
				ans+=max(save,tmp.second);
				break;
			}
			auto it=x.upper_bound(mp(tmp.second,10000000000));
			ll val1,val2,val3;
			if(it==x.end())
				val1=LLONG_MAX;
			else
				val1=abs(it->first-tmp.second);
			if(it==x.begin())
				val2=LLONG_MAX;
			else
			{
				it--;
				val2=abs(it->first-tmp.second);
			}
			val3=abs(save-tmp.second);
			ll minVal=min(val1,min(val2,val3));
			if(minVal==val3)
			{
				ans+=max(save,tmp.second);
				break;
			}
			else if(minVal==val2)
			{
				ans++;
				ans+=max(it->first,tmp.second);
				tmp=*it;
				x.erase(it);
			}
			else if(minVal==val1)
			{
				ans++;
				if(val2!=LLONG_MAX)
					it++;
				ans+=max(it->first,tmp.second);
				tmp=*it;
				x.erase(it);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}