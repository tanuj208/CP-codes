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
	ll i,j;
	if((n==2 || n==3) && a==1 && b==1)
	{
		cout<<"NO\n";
		return 0;
	}
	if(a>1 && b>1)
	{
		cout<<"NO\n";
		return 0;
	}
	ll flag=0;
	if(a==1)
	{
		ll temp=a;
		a=b;
		b=temp;
		flag=1;
	}
	ll ans[1005][1005];
	if(a!=1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j || i<=a-2 || j<=a-2)
					ans[i][j]=0;
				else
					ans[i][j]=1;
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j+1 || j==i+1)
					ans[i][j]=1;
				else
					ans[i][j]=0;
			}
		}
	}
	if(flag==1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue;
				if(ans[i][j]==0)
					ans[i][j]=1;
				else
					ans[i][j]=0;
			}
		}
	}
	cout<<"YES\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<ans[i][j];
		cout<<endl;
	}
	return 0;
}