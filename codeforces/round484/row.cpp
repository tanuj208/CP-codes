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
	string s;
	cin>>s;
	ll i;
	if(n==1)
	{
		if(s[0]=='0')
			cout<<"No\n";
		else
			cout<<"Yes\n";
		return 0;
	}
	for(i=0;i<n-1;i++)
	{
		if(s[i]=='1' && s[i+1]=='1')
		{
			cout<<"No\n";
			return 0;
		}
		if(s[i]=='0')
		{
			if(i!=0)
			{
				if(s[i-1]=='0' && s[i+1]=='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
			else
			{
				if(s[i+1]=='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
		}
	}
	if(s[n-1]=='0' && s[n-2]=='0')
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}