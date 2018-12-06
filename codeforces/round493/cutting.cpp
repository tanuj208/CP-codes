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
	ll n,b;
	cin>>n>>b;
	ll i,val;
	vector<ll> a;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	ll evens=0,odds=0;
	vector<ll> cost;
	for(i=0;i<n-1;i++)
	{
		if(a[i]%2==0)
			evens++;
		else
			odds++;
		if(evens==odds)
			cost.pb(abs(a[i+1]-a[i]));
	}
	sort(cost.begin(),cost.end());
	ll c=0;
	ll cuts=0;
	for(i=0;i<sz(cost);i++)
	{
		c+=cost[i];
		if(c>b)
			break;
		cuts++;
	}
	cout<<cuts<<endl;
	return 0;
}