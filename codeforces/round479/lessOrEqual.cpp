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
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	sort(a.begin(),a.end());
	if(k==0)
	{
		if(a[0]==1)
			cout<<"-1\n";
		else
			cout<<"1\n";
		return 0;
	}
	if(a[k]==a[k-1])
		cout<<"-1\n";
	else
		cout<<a[k-1]<<endl;
	return 0;
}