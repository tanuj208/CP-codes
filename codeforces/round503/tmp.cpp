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
	vector<ll> p(3005),c(3005);
	set<pii> vote[3005];
	ll i;
	set<pii> t;
	for(i=1;i<=n;i++)
	{
		ll a,b;
		cin>>a>>b;
		p[i]=a;
		c[i]=b;
		vote[a].insert(mp(b,i));
	}
	for(i=1;i<=m;i++)
		t.insert(mp(sz(vote[i]),i));
	auto it=t.end();
	it--;
	pii tmp=*it;
	ll ans=0;
	while(tmp.second!=1)
	{
		ll v=tmp.first;   // most votes to a party
		ll j=tmp.second;  // party with most votes
		ll minn=LLONG_MAX;
		ll secondMinn=LLONG_MAX;
		ll index;
		for(i=2;i<=m;i++)
		{
			if(sz(vote[i])==0)
				continue;
			ll xx=vote[i].begin()->first;
			if(minn>xx)
			{
				secondMinn=minn;
				minn=xx;
				index=i;
			}
			else if(secondMinn>xx)
				secondMinn=xx;
		}
		ll minTowinning=vote[j].begin()->first;
		// secondMinn=min(secondMinn,minTowinning);
		if(sz(vote[1])<sz(vote[j]))
		{
			if(minn+secondMinn<minTowinning)
			{
				ans+=minn;
				t.insert(mp(sz(vote[1])+1,1));
				t.erase(mp(sz(vote[1]),1));
				t.insert(mp(sz(vote[index])-1,index));
				t.erase(mp(sz(vote[index]),index));
				vote[1].insert(mp(minn,vote[index].begin()->second));
				vote[index].erase(vote[index].begin());
			}
			else
			{
				ans+=minTowinning;
				t.insert(mp(sz(vote[1])+1,1));
				t.erase(mp(sz(vote[1]),1));
				t.insert(mp(sz(vote[j])-1,j));
				t.erase(mp(sz(vote[j]),j));
				vote[1].insert(mp(minTowinning,vote[j].begin()->second));
				vote[j].erase(vote[j].begin());
			}
		}
		else
		{
			if(minn<minTowinning)
			{
				ans+=minn;
				t.insert(mp(sz(vote[1])+1,1));
				t.erase(mp(sz(vote[1]),1));
				t.insert(mp(sz(vote[index])-1,index));
				t.erase(mp(sz(vote[index]),index));
				vote[1].insert(mp(minn,vote[index].begin()->second));
				vote[index].erase(vote[index].begin());
			}
			else
			{
				ans+=minTowinning;
				t.insert(mp(sz(vote[1])+1,1));
				t.erase(mp(sz(vote[1]),1));
				t.insert(mp(sz(vote[j])-1,j));
				t.erase(mp(sz(vote[j]),j));
				vote[1].insert(mp(minTowinning,vote[j].begin()->second));
				vote[j].erase(vote[j].begin());
			}
		}
		it=t.end();
		it--;
		tmp=*it;
	}
	cout<<ans<<endl;
	return 0;
}