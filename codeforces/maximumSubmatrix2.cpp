#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef long long ll;
typedef pair<int,int> pii;

const int lt=100005;
int mod=1000000007;
int dp[5003][5003];
int andp[5003][5003];
int n,m;

int func(int i,int j)
{
	if(i<1 || j>m || i>j)
		return 0;
	if(andp[i][j]!=INT_MIN)
		return andp[i][j];
	andp[i][j]=dp[i][j]+func(i-1,j)+func(i,j+1)-func(i-1,j+1);
	return andp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	vector<string> x;
	int i;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		x.pb(s);
	}
	int j;
	for(i=0;i<=5000;i++)
		for(j=0;j<=5000;j++)
			andp[i][j]=INT_MIN;
	for(i=0;i<n;i++)
	{
		string s=x[i];
		int st=0;
		for(j=0;j<m;j++)
		{
			if(s[j]=='1' && st==0)
				st=j+1;
			else if(s[j]=='0' && st!=0)
				dp[st][j]++,st=0;
		}
		if(st!=0)
			dp[st][m]++,st=0;
	}
	int ans=0;
	for(i=1;i<=m;i++)
		for(j=i;j<=m;j++)
			ans=max(ans,(j-i+1)*func(i,j));
	cout<<ans<<endl;
	return 0;
}