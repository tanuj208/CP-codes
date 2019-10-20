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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll i;
		vector<ll> s;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			s.pb(val);
		}
		sort(s.begin(),s.end());
		reverse(s.begin(),s.end());
		ll cnt=k-1;
		while(s[cnt]==s[k-1])
			cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}