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
	string s,t;
	cin>>s>>t;
	ll i;
	ll flag=0;
	if(m<n-1)
	{
		cout<<"NO\n";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(s[i]!='*' && s[i]!=t[i])
		{
			cout<<"NO\n";
			exit(0);
		}
		else if(s[i]=='*')
		{
			flag=1;
			break;
		}
	}
	if(flag==0 && n!=m)
	{
		cout<<"NO\n";
		return 0;
	}
	ll j=m-1;
	for(i=n-1;i>=0;i--)
	{
		if(s[i]!='*' && s[i]!=t[j])
		{
			cout<<"NO\n";
			exit(0);
		}
		else if(s[i]=='*')
			break;
		j--;
	}
	cout<<"YES\n";
	return 0;
}