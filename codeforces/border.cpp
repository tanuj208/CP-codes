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
	ll i,val;
	vector<ll> a;
	cin>>val;
	a.pb(val);
	ll gcd=val;
	for(i=1;i<n;i++)
	{
		cin>>val;
		a.pb(val);
		gcd=__gcd(gcd,val);
	}
	gcd%=k;
	set<ll> ans;
	ll x=gcd;
	while(ans.find(x)==ans.end())
	{
		ans.insert(x);
		x+=gcd;
		x%=k;
	}
	cout<<sz(ans)<<endl;
	for(auto it=ans.begin();it!=ans.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}