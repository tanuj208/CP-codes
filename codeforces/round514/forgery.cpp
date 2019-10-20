#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll arr[1005][1005];
ll ans[1005][1005];
ll n,m;

bool checkfill(ll i,ll j)
{
	if(i<0 || j<0)
		return false;
	if(i+2>=n || j+2>=m)
		return false;
	if(arr[i][j]==0 || arr[i+1][j]==0 || arr[i+2][j]==0 || arr[i][j+1]==0 || arr[i+2][j+1]==0 || arr[i][j+2]==0 || arr[i+1][j+2]==0 || arr[i+2][j+2]==0)
		return false;
	ans[i][j]=1,ans[i+1][j]=1,ans[i+2][j]=1,ans[i][j+1]=1,ans[i+2][j+1]=1,ans[i][j+2]=1,ans[i+1][j+2]=1,ans[i+2][j+2]=1;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ans[i][j]=0;
			char c;
			cin>>c;
			if(c=='.')
				arr[i][j]=0;
			else
				arr[i][j]=1;
		}
	}
	ll k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(ans[i][j]==1 && arr[i][j]==0)
			{
				cout<<"NO\n";
				return 0;
			}
			else if(ans[i][j]==0 && arr[i][j]==1)
			{
				if(!checkfill(i,j) && !checkfill(i-1,j) && !checkfill(i-2,j) && !checkfill(i,j-1) && !checkfill(i,j-2) && !checkfill(i-1,j-2) && !checkfill(i-2,j-1) && !checkfill(i-2,j-2))
				{
					cout<<"NO\n";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	return 0;
}