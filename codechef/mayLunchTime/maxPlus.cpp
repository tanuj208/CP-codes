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
		ll n,m;
		cin>>n>>m;
		ll mat[1005][1005];
		ll vd[1005][1005];
		ll vu[1005][1005];
		ll hr[1005][1005];
		ll hl[1005][1005];
		ll i,j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>mat[i][j];
		ll ans=-100000005;
		for(i=1;i<n-1;i++)
		{
			hl[i][1]=0;
			for(j=2;j<m-1;j++)
				hl[i][j]=max(max(hl[i][j-1]+mat[i][j-2],mat[i][j-2]),(ll)0);
		}
		for(i=1;i<n-1;i++)
		{
			hr[i][m-2]=0;
			for(j=m-3;j>0;j--)
				hr[i][j]=max(max(hr[i][j+1]+mat[i][j+2],mat[i][j+2]),(ll)0);
		}
		for(j=1;j<m-1;j++)
		{
			vu[1][j]=0;
			for(i=2;i<n-1;i++)
				vu[i][j]=max(max(vu[i-1][j]+mat[i-2][j],mat[i-2][j]),(ll)0);
		}
		for(j=1;j<m-1;j++)
		{
			vd[n-2][j]=0;
			for(i=n-3;i>0;i--)
				vd[i][j]=max(max(vd[i+1][j]+mat[i+2][j],mat[i+2][j]),(ll)0);
		}
		for(i=1;i<n-1;i++)
		{
			for(j=1;j<m-1;j++)
			{
				ll temp=mat[i][j]+mat[i-1][j]+mat[i+1][j]+mat[i][j-1]+mat[i][j+1];
				temp+=hl[i][j]+hr[i][j]+vu[i][j]+vd[i][j];
				ans=max(ans,temp);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}