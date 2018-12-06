#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll mat[104][104];
ll cont=0;
ll ansmat[104][104];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			char c;
			cin>>c;
			if(c=='.')
				mat[i][j]=0;
			else
				mat[i][j]=1;
		}
	}
	ll m;
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
			ansmat[i][j]=0;
	for(i=0;i<n;i++)
	{
		cont=0;
		for(j=0;j<n;j++)
		{
			if(mat[i][j]==0)
			{
				cont++;
			}
			if(mat[i][j]==1)
			{
				if(cont>=k)
				{
					ll x=min(cont-k+1,k);
					for(m=0;m<x;m++)
					{
						ansmat[i][j-1-m]+=(m+1);
						if((j-1-m)!=(j-cont+m))
							ansmat[i][j-cont+m]+=(m+1);
					}
					for(m=x;m<cont-x;m++)
						ansmat[i][j-cont+m]+=x;
				}
				cont=0;
			}
			if(mat[i][j]!=1 && j==n-1)
			{
				if(cont>=k)
				{
					ll x=min(cont-k+1,k);
					for(m=0;m<x;m++)
					{
						ansmat[i][j-m]+=(m+1);
						if((j-m)!=(j-cont+m+1))
							ansmat[i][j-cont+m+1]+=(m+1);
					}
					for(m=x;m<cont-x;m++)
						ansmat[i][j-cont+m+1]+=x;
				}
				cont=0;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		cont=0;
		for(j=0;j<n;j++)
		{
			if(mat[j][i]==0)
				cont++;
			if(mat[j][i]==1)
			{
				if(cont>=k)
				{
					ll x=min(cont-k+1,k);
					for(m=0;m<x;m++)
					{
						ansmat[j-1-m][i]+=(m+1);
						if((j-1-m)!=(j-cont+m))
							ansmat[j-cont+m][i]+=(m+1);
					}
					for(m=x;m<cont-x;m++)
						ansmat[j-cont+m][i]+=x;
				}
				cont=0;
			}
			if(mat[j][i]!=1 && j==n-1)
			{
				if(cont>=k)
				{
					ll x=min(cont-k+1,k);
					// cout<<x<<endl;
					// cout<<i<<endl;
					for(m=0;m<x;m++)
					{
						ansmat[j-m][i]+=(m+1);
						if((j-cont+m+1)!=(j-m))
							ansmat[j-cont+m+1][i]+=(m+1);
					}
					for(m=x;m<cont-x;m++)
						ansmat[j-cont+m+1][i]+=x;
				}
				cont=0;
			}
		}
	}
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 		cout<<ansmat[i][j]<<" ";
	// 	cout<<endl;
	// }
	ll maximum=0;
	ll ansi;
	ll ansj;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(maximum<=ansmat[i][j])
			{
				maximum=ansmat[i][j];
				ansi=i+1;
				ansj=j+1;
			}
		}
	}
	cout<<ansi<<" "<<ansj<<endl;
	return 0;
}