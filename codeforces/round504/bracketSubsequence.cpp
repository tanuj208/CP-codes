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
	ll i;
	string s;
	cin>>s;
	ll x=(n-k)/2;
	ll cnt=0;
	string ans;
	ll f=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='(' && x!=0)
			cnt++,x--;
		else if(s[i]==')' && cnt>0 && f==0)
			cnt--;
		else if(s[i]=='(' && x==0)
		{
			f++;
			ans.pb('(');
		}
		else if(s[i]==')' && f!=0)
		{
			f--;
			ans.pb(')');
		}
	}
	cout<<ans<<endl;
	return 0;
}