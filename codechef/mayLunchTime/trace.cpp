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
		ll n;
		cin>>n;
		ll mat[103][103];
		ll i,j;
		ll ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>mat[i][j];
				ans=max(ans,mat[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				ll temp=0;
				ll k=0;
				while(i+k<n && j+k<n)
				{
					temp+=mat[i+k][j+k];
					k++;
				}
				ans=max(ans,temp);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}