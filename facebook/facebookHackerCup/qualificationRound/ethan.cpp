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
	ll i;
	for(i=1;i<=t;i++)
	{
		string s;
		cin>>s;
		ll j,k=0;
		ll impossible=1;
		ll flag=0;
		ll st;
		for(j=1;j<sz(s);j++)
		{
			if(s[j]==s[0] && flag==0)
			{
				flag=1;
				st=j;
				k++;
				continue;
			}
			if(flag==1 && s[j]!=s[k])
			{
				impossible=0;
				break;
			}
			else if(flag==1 && s[j]==s[k])
				k++;
		}
		cout<<"Case #"<<i<<": ";
		if(impossible==1)
		{
			cout<<"Impossible\n";
			continue;
		}
		for(j=0;j<st;j++)
			cout<<s[j];
		cout<<s<<"\n";
	}
	return 0;
}