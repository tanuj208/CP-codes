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
	ll n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	ll i;
	ll ans=0,flag;
	for(i=0;i<sz(s);i++)
	{
		if(a==0 && b==0)
			break;
		if(s[i]=='*')
			continue;
		if(i==0 || s[i-1]=='*')
		{
			if(a>=b)
			{
				a--;
				flag=1;
			}
			else
			{
				b--;
				flag=0;
			}
			ans++;
		}
		else
		{
			if(flag==1)
			{
				flag=0;
				if(b==0)
					continue;
				b--;
			}
			else
			{
				flag=1;
				if(a==0)
					continue;
				a--;
			}
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}