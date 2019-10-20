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
	ll i;
	for(i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r;
	}
	cout<<0;
	ll last=0;
	for(i=1;i<n;i++)
	{
		if(last==0)
		{
			cout<<1;
			last=1;
		}
		else
		{
			cout<<0;
			last=0;
		}
	}
	cout<<endl;
	return 0;
}