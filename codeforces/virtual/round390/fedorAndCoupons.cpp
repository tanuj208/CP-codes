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
	ll n,k;
	cin>>n>>k;
	vector<pii> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	sort(a.begin(),a.end());
	if(k==1)
	{
		ll range=0;
		ll ans;
		for(i=0;i<n;i++)
		{
			if(range<a[i].second-a[i].first+1)
			{
				range=a[i].second-a[i].first+1;
				ans=i+1;
			}
		}
		cout<<range<<endl<<ans<<endl;
		return 0;
	}
	set<ll> took;
	multiset<ll> rs;
	pii common=mp(LLONG_MIN,LLONG_MAX);
	for(i=0;i<k;i++)
	{
		took.insert(i);
		ll x=a[i].first;
		ll y=a[i].second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		rs.insert(y);
	}
	ll ans;
	ans=common.second-common.first+1;
	for(i=k;i<n;i++)
	{
		auto it=took.begin();
		ll i1=*it;
		it++;
		ll i2=*it;
		if(a[i1].second>=a[i2].second)
		{
			took.erase(it);
			rs.erase(rs.find(a[i2].second));
		}
		else
		{
			it--;
			took.erase(it);
			if(common.first<a[i2].first)
				common.first=a[i2].first;
			auto itt=rs.begin();
			if(*itt==a[i1].second)
			{
				itt++;
				common.second=*itt;
			}
			rs.erase(rs.find(a[i1].second));
		}
		took.insert(i);
		rs.insert(a[i].second);
		ll x=a[i].first;
		ll y=a[i].second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		ans=max(ans,common.second-common.first+1);
	}
	if(ans<=0)
	{
		cout<<"0\n";
		for(i=0;i<k;i++)
			cout<<i+1<<" ";
		cout<<endl;
		return 0;
	}
	cout<<ans<<endl;
	rs.clear();
	took.clear();
	common.first=LLONG_MIN;
	common.second=LLONG_MAX;
	for(i=0;i<k;i++)
	{
		took.insert(i);
		ll x=a[i].first;
		ll y=a[i].second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		rs.insert(y);
	}
	if(ans==common.second-common.first+1)
	{
		for(auto it:took)
			cout<<it+1<<" ";
		cout<<endl;
		return 0;
	}
	for(i=k;i<n;i++)
	{
		auto it=took.begin();
		ll i1=*it;
		it++;
		ll i2=*it;
		if(a[i1].second>=a[i2].second)
		{
			took.erase(it);
			rs.erase(rs.find(a[i2].second));
		}
		else
		{
			it--;
			took.erase(it);
			if(common.first<a[i2].first)
				common.first=a[i2].first;
			auto itt=rs.begin();
			if(*itt==a[i1].second)
			{
				itt++;
				common.second=*itt;
			}
			rs.erase(rs.find(a[i1].second));
		}
		took.insert(i);
		rs.insert(a[i].second);
		ll x=a[i].first;
		ll y=a[i].second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		if(common.second-common.first+1==ans)
			break;
	}
	for(auto it:took)
		cout<<it+1<<" ";
	cout<<endl;
	return 0;
}