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
	ll i,j,k;
	ll ans=0;
	ll n=sz(s);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=i;k<=j;k++)
			{
				if(s[k]!=s[j-k+i])
				{
					ans=max(ans,j-i+1);
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}