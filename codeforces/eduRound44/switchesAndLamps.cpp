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
	ll countt[2005]={0};
	ll i;
	vector<string> x;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		x.pb(s);
		ll j;
		for(j=0;j<m;j++)
			if(s[j]=='1')
				countt[j]++;
	}
	for(i=0;i<n;i++)
	{
		string s=x[i];
		ll j;
		ll flag=0;
		for(j=0;j<m;j++)
			if(s[j]=='1' && countt[j]==1)
				flag=1;
		if(flag==0)
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}