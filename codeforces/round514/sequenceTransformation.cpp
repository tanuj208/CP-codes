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
	set<ll> x;
	ll i;
	for(i=1;i<=n;i++)
		x.insert(i);
	ll r=2;
	vector<ll> rem;
	ll gcd=1;
	while(!x.empty())
	{
		if(sz(x)==3)
		{
			cout<<gcd<<" "<<gcd<<" ";
			x.erase(x.begin());
			x.erase(x.begin());
			cout<<*x.begin()<<" ";
			x.erase(x.begin());
			continue;
		}
		for(auto it=x.begin();it!=x.end();it++)
		{
			ll xx=*it;
			if(xx%r!=0)
			{
				cout<<gcd<<" ";
				rem.pb(xx);
			}
		}
		gcd*=2;
		r*=2;
		for(i=0;i<sz(rem);i++)
			x.erase(rem[i]);
		rem.clear();
	}
	cout<<endl;
	return 0;
}