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
	string s1,s2;
	cin>>s1>>s2;
	ll ans=0,i;
	for(i=0;i<sz(s1)-1;i++)
	{
		if(s1[i]=='X' && s2[i]=='X')
			continue;
		if(s1[i]=='0' && s2[i]=='0')
		{
			if(s1[i+1]=='X' && s2[i+1]=='X')
				continue;
			ans++;
			if(s1[i+1]=='0' && s2[i+1]=='0')
				s1[i+1]='X';
			else
				s1[i+1]='X',s2[i+1]='X';
		}
		else
		{
			if(s1[i+1]=='0' && s2[i+1]=='0')
			{
				ans++;
				s1[i+1]='X';
				s2[i+1]='X';
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}