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
	ll n,k;
	cin>>n>>k;
	vector<pair<pii,ll> > a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.pb(mp(mp(x,y),i));
	}
	sort(a.begin(),a.end());
	ll anant[300005];
	for(i=0;i<n;i++)
		anant[i]=a[i].second;
	if(k==1)
	{
		ll range=0;
		ll ans;
		for(i=0;i<n;i++)
		{
			if(range<a[i].first.second-a[i].first.first+1)
			{
				range=a[i].first.second-a[i].first.first+1;
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
		ll x=a[i].first.first;
		ll y=a[i].first.second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		rs.insert(y);
	}
	ll ans;
	ans=common.second-common.first+1;
	cout<<ans<<endl;
	for(i=k;i<n;i++)
	{
		auto it=took.begin();
		ll i1=*it;
		it++;
		ll i2=*it;

		if(a[i1].first.second>=a[i2].first.second)
		{
			took.erase(it);
			rs.erase(rs.find(a[i2].first.second));
		}
		else
		{
			it--;
			took.erase(it);
			if(common.first<a[i2].first.first)
				common.first=a[i2].first.first;
			auto itt=rs.begin();
			if(*itt==a[i1].first.second)
			{
				itt++;
				common.second=*itt;
			}

			rs.erase(rs.find(a[i1].first.second));
		}
		took.insert(i);
		rs.insert(a[i].first.second);
		ll x=a[i].first.first;
		ll y=a[i].first.second;
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
		ll x=a[i].first.first;
		ll y=a[i].first.second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		rs.insert(y);
	}
	if(ans==common.second-common.first+1)
	{
		for(auto it:took)
			cout<<anant[it]+1<<" ";
		cout<<endl;
		return 0;
	}
	for(i=k;i<n;i++)
	{
		auto it=took.begin();
		ll i1=*it;
		it++;
		ll i2=*it;
		if(a[i1].first.second>=a[i2].first.second)
		{
			took.erase(it);
			rs.erase(rs.find(a[i2].first.second));
		}
		else
		{
			it--;
			took.erase(it);
			if(common.first<a[i2].first.first)
				common.first=a[i2].first.first;
			auto itt=rs.begin();
			if(*itt==a[i1].first.second)
			{
				itt++;
				common.second=*itt;
			}
			rs.erase(rs.find(a[i1].first.second));
		}
		took.insert(i);
		rs.insert(a[i].first.second);
		ll x=a[i].first.first;
		ll y=a[i].first.second;
		if(x>common.first)
			common.first=x;
		if(y<common.second)
			common.second=y;
		if(common.second-common.first+1==ans)
			break;
	}
	for(auto it:took)
		cout<<anant[it]+1<<" ";
	cout<<endl;
	return 0;
}