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
	string s;
	cin>>s;
	ll i;
	ll o=0,d=0;
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='-')
			d++;
		else
			o++;
	}
	if(o<=1 || d==0)
	{
		cout<<"YES\n";
		return 0;
	}
	if(d%o==0)
	{
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}