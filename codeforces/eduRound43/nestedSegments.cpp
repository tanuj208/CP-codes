#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool cmp(pair<pii,ll> a, pair<pii,ll> b)
{
	if(a.first.first<b.first.first)
		return true;
	if(a.first.first>b.first.first)
		return false;
	if(a.first.first==b.first.first)
	{
		if(a.first.second>b.first.second)
			return true;
		else
			return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<pair<pii,ll> > a;
	for(i=0;i<n;i++)
	{
		ll val1,val2;
		cin>>val1>>val2;
		a.pb(mp(mp(val1,val2),i));
	}
	sort(a.begin(),a.end(),cmp);
	ll m=a[0].first.second;
	ll ind=0;
	for(i=1;i<n;i++)
	{
		if(a[i].first.second<=m)
		{
			cout<<a[i].second+1<<" "<<a[ind].second+1<<endl;
			return 0;
		}
		m=a[i].first.second;
		ind=i;
	}
	cout<<"-1 -1\n";
	return 0;
}