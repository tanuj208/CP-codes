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
	vector<pii> a;
	ll i,val;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(mp(val,i+1));
		sum+=val;
	}
	if(n==1)
	{
		cout<<"-1\n";
		return 0;
	}
	sort(a.begin(),a.end());
	if(sum-a[0].first==a[0].first)
		cout<<"-1\n";
	else
		cout<<"1\n"<<a[0].second<<endl;
	return 0;
}