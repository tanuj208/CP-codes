#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll a,b;
ll mat[1005][1005];

void calcAB(ll i,ll j)
{
	ll x=mat[i][j];
	a=0;
	b=0;
	while(x%2==0 && x!=0)
	{
		a++;
		x/=2;
	}
	x=mat[i][j];
	while(x%5==0 && x!=0)
	{
		b++;
		x/=5;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	pii dp[1005][1005];
	pii command[1005][1005];
	ll i,j;
	ll zerohai=0;
	ll iJahanzerohai,jJahanzerohai;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]==0)
			{
				zerohai=1;
				iJahanzerohai=i;
				jJahanzerohai=j;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			calcAB(i,j);
			if(i==0)
			{
				if(j==0)
				{
					dp[i][j].first=a;
					dp[i][j].second=b;
					continue;
				}
				dp[i][j].first=a+dp[i][j-1].first;
				dp[i][j].second=b+dp[i][j-1].second;
				command[i][j]=mp(1,3);
				// 1 left first 3 left second
			}
			else
			{
				if(j==0)
				{
					dp[i][j].first=a+dp[i-1][j].first;
					dp[i][j].second=b+dp[i-1][j].second;
					command[i][j]=mp(2,4);
					// 2 up first 4 up second
					continue;
				}
				dp[i][j].first=a+min(dp[i-1][j].first,dp[i][j-1].first);
				if(a+dp[i-1][j].first==dp[i][j].first)
					command[i][j].first=2;
				else
					command[i][j].first=1;
				dp[i][j].second=b+min(dp[i-1][j].second,dp[i][j-1].second);
				if(b+dp[i][j-1].second==dp[i][j].second)
					command[i][j].second=3;
				else
					command[i][j].second=4;
			}
		}
	}
	ll ans=min(dp[n-1][n-1].first,dp[n-1][n-1].second);
	if(zerohai==1 && ans>1)
	{
		cout<<"1\n";
		for(i=0;i<iJahanzerohai;i++)
			cout<<"D";
		for(i=0;i<jJahanzerohai;i++)
			cout<<"R";
		for(i=iJahanzerohai;i<n-1;i++)
			cout<<"D";
		for(i=jJahanzerohai;i<n-1;i++)
			cout<<"R";
		cout<<endl;
		return 0;
	}
	cout<<ans<<endl;
	ll k;
	i=n-1;
	j=n-1;
	ll flag;
	if(dp[i][j].first<dp[i][j].second)
		flag=1;
	else
		flag=2;
	string s;
	for(k=0;k<(2*(n-1));k++)
	{
		ll x;
		if(flag==1)
		{
			x=command[i][j].first;
			if(x==1)
			{
				s+="R";
				j--;
			}
			else
			{
				s+="D";
				i--;
			}
		}
		else
		{
			x=command[i][j].second;
			if(x==3)
			{
				s+="R";
				j--;
			}
			else
			{
				s+="D";
				i--;
			}
		}
	}
	for(i=sz(s)-1;i>=0;i--)
		cout<<s[i];
	cout<<endl;
	return 0;
}